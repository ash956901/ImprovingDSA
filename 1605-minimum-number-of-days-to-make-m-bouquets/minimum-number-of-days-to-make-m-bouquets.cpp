class Solution {
public:
    bool solve(vector<int> &bloomDay,int day,int m,int k){
      
        int bq;
        int f;
        bq=f=0;
        for(int i=0;i<bloomDay.size();i++){
            if(day>=bloomDay[i]){
                f+=1;
                if(f==k) {
                    bq+=1;
                    f=0;
                }
            }
            else{
                f=0;
                //drop if not adjacent 
            }
        }

       
        return bq>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>(long long)bloomDay.size()) return -1;
         int l=*min_element(bloomDay.begin(),bloomDay.end());
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int mid=l+(r-l)/2;
        while(l<r){
            if(solve(bloomDay,mid,m,k)){
                r=mid;
            }
            else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }

        return l;
    
    }
};