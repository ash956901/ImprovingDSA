class Solution {
public:
    int giveMinutes(vector<int> &strength,int k){
        int minutes=0;
        int X=1;
        for(int i=0;i<strength.size();i++){
            minutes+=(strength[i]+X-1)/X;
            X+=k;
        }

        return minutes;
    }
    int findMinimumTime(vector<int>& strength, int k) {
        sort(strength.begin(),strength.end());

        int ans=INT_MAX;

        do{
            ans=min(ans,giveMinutes(strength,k));
        }while(next_permutation(strength.begin(),strength.end()));

        return ans;
    }
};