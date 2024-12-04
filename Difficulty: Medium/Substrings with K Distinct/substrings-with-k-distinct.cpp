//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int solve(string str,int k){
        if(k==0) return 0;
         int i=0;
        unordered_map<char,int> freq;
        int distinct=0;
        int count=0;
        for(int j=0;j<str.size();j++){
            freq[str[j]]++;
            if(freq[str[j]]==1) distinct++;
            while(distinct>k){
                freq[str[i]]--;
                 if(freq[str[i]]==0) distinct--;
                i++;
            }
            count+=j-i+1;
            
              
        }
        
        return count;
    }
    int countSubstr(string str, int k) {
       return solve(str,k)-solve(str,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.countSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends