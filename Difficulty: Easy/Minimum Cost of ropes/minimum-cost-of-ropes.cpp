//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(auto i:arr){
            pq.push(i);
        }
        
        int cost=0;
        
        while(!pq.empty()){
            //do nikalo
            auto first=pq.top();pq.pop();
            
            //check for next
            int second;
            if(!pq.empty()){
                second=pq.top();pq.pop();
            }
            else{
                break;
            }
            
            int sum=first+second;
            cost+=sum;
            pq.push(sum);
        }
        
        
        return cost;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends