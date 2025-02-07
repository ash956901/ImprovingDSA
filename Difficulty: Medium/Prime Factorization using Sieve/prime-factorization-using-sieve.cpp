//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        vector<int> smallestPrimeFactor(1000001,1);
        smallestPrimeFactor[0]=0;
        for(int i=2;i<=N;i++){
            if(smallestPrimeFactor[i]==1){
                for(int j=i;j<=N;j+=i){
                    if(smallestPrimeFactor[j]==1){
                         smallestPrimeFactor[j]=i;
                    }
                   
                }
            }
        }
        
        
        
        vector<int> ans;
        while(N!=1){
            ans.push_back(smallestPrimeFactor[N]);
            N/=smallestPrimeFactor[N];
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends