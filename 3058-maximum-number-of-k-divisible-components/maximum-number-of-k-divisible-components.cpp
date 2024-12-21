class Solution {
public:
    int dfs(vector<vector<int>>& adj,int node,vector<int>& vis,vector<int>& values,int k,int& cnt){
         vis[node] = 1;
         long long sum = values[node]%k;
         for(auto u:adj[node]){
            if(!vis[u]){
              long long curr = dfs(adj,u,vis,values,k,cnt);
              if(curr%k==0)cnt++;
              else{
                sum = (sum+curr);
              }
            }
           
         }
    return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
       vector<vector<int>> adj(n);

       for(auto u:edges){
        int x = u[0];
        int y = u[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
       }

       int cnt =0;
       
       vector<int> vis(n,0);
       dfs(adj,0,vis,values,k,cnt);
       int ans = cnt+1;

       return ans;

    }
};