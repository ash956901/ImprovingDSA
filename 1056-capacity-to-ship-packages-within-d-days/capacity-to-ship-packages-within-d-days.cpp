class Solution {
public:
    bool solve(vector<int>& w,int cap,int d){
        int sum,day;
        sum=day=0;
        for(int i=0;i<w.size();i++){
           
            if(sum+w[i]>cap){
                sum=w[i];
                 if(sum>cap) return false;
                day+=1;
            }
            else{
                 sum+=w[i];
            }
           
        }
        day+=1;
        return day<=d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=1;
        int r=accumulate(weights.begin(),weights.end(),0);
        int mid=l+(r-l)/2;
        while(l<r){
            if(solve(weights,mid,days)){
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