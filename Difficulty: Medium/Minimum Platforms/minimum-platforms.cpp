//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
       vector<vector<int>> se;
       priority_queue<int,vector<int>,greater<int>> pq;
       for(int i=0;i<arr.size();i++){
            vector<int> temp(2,0);
            temp[0]=arr[i];
            temp[1]=dep[i];
            se.push_back(temp);
       }
       
       sort(se.begin(),se.end());
       
       vector<vector<int>> merged;
       merged.push_back(se[0]);
       int ans=1;
       int count=1;
       pq.push(se[0][1]);
       for(int i=1;i<se.size();i++){
           auto &last=merged.back();
           auto &curr=se[i];
           
           if(curr[0]<=last[1]){
               pq.push(curr[1]);
               count++;
               while(pq.top()<curr[0]){
                   pq.pop();
                   count--;
               }
               ans=max(ans,count);
               last[1]=max(curr[1],last[1]);
           }
           else{
               count=1;
               while(!pq.empty()){pq.pop();}
               pq.push(curr[1]);
               merged.push_back(curr);
           }
       }
       
       return ans;
       
       
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends