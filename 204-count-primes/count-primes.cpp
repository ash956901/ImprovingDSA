class Solution {
public:
    int countPrimes(int n) {
        vector<bool> check(n+1,true);
        int ans=0;
        for(int i=2;i<n;i++){
            if(check[i]){
                ans++;
                for(int j=2*i;j<n;j+=i){
                    check[j]=false;
                }
            }
        }

     
        return ans;
    }
};