class Solution {
public:
    bool solve(vector<int> &piles,int rate,int h){
        int hrs=0;
        int q,r;
        q=r=0;
        for(int i=0;i<piles.size();i++){
            q=piles[i]/rate;
            r=piles[i]-(rate*q);
            if(r==0) hrs+=q;
            else hrs+=(q+1);
        }

        return hrs<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int mid=l+(r-l)/2;
        while(l<r){
            if(solve(piles,mid,h)){
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