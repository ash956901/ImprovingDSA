//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(vector<int> &arr,int index,int sum,int target, vector<vector<int>> &dp){
        if(index>=arr.size()){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        } 
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        
        //take
        int include=solve(arr,index+1,sum+arr[index],target,dp);
        
        //dont take
        int exclude=solve(arr,index+1,sum,target,dp);
        
        
        return dp[index][sum]=include+exclude;
    }
    int perfectSum(vector<int>& arr, int target) {
      int sum=0;
      for(auto i:arr) sum+=i;
      int n=arr.size();
       vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
      return solve(arr,0,0,target,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends