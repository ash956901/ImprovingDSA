//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int onXor(int n){
        int rem=n%4;
        if(rem==0) return n;
        if(rem==1) return 1;
        if(rem==2) return n+1;
        if(rem==3) return 0;
    }
    int findXOR(int l, int r) {
        
        //first find from 1 to l-1
        //then find from 1 to r;
        //then xor the two;
        
        return onXor(r)^onXor(l-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends