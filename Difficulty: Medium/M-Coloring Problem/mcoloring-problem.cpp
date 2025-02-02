//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(unordered_map<int,list<int>> &adj,int node,int col,vector<int> &color){
        for(auto i:adj[node]){
            if(col==color[i]) return false;
        }
        
        return true;
    }
    bool solve(unordered_map<int,list<int>> &adj,int m,int v,int node,vector<int> &color){
       if(node==v) return true;
  
       for(int i=0;i<m;i++){
           if(isSafe(adj,node,i,color)){
               color[node]=i;
               if(solve(adj,m,v,node+1,color)) return true;
               color[node]=-1;
           }
       }
       
       
       return false ;
    }
    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
       unordered_map<int,list<int>> adj;
       for(auto i:edges){
           adj[i.first].push_back(i.second);
           adj[i.second].push_back(i.first);
       }
       
       vector<int> color(v,-1);
       return solve(adj,m,v,0,color);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << "\n~\n"; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends