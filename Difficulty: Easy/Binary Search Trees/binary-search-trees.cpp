//{ Driver Code Starts
// Initial Template for C++

// {Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        if(arr.size()==1) return true;
        unordered_map<int,int> checkFreq;
        for(auto i:arr){
            checkFreq[i]++;
            if(checkFreq[i]>1) return false;
        }
        int curr=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]<curr){
                return false;
            }
            curr=arr[i];
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            nums[i] = k;
        }

        Solution ob;
        bool res = ob.isBSTTraversal(nums);
        if (res)
            cout << "True";
        else
            cout << "False";

        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends