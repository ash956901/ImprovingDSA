//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        
        int dead=*max_element(deadline.begin(),deadline.end());
        vector<int> slots(dead+1,-1);
        
        vector<pair<int,int>> jobs;
        
        for(int i=0;i<deadline.size();i++){
            jobs.push_back(make_pair(deadline[i],profit[i]));
        }
        
        sort(jobs.begin(),jobs.end(),[](pair<int,int> &a,pair<int,int> &b){
            return a.second>b.second;
        });
        
        
        vector<int> ans;
        int count=0;
        int total=0;
        for(int i=0;i<jobs.size();i++){
            int p=jobs[i].second;
            int d=jobs[i].first;
            
            for(int i=d;i>=1;i--){
                if(slots[i]==-1){
                    count++;
                    slots[i]=p;
                    total+=p;
                    break;
                }
            }
        }
        
        ans.push_back(count);
        ans.push_back(total);
        
        
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends