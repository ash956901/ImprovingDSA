class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         unordered_map<int, list<int>> adj;
         int n=graph.size();
        vector<int> indegree(n, 0);
        vector<int> topo;
        queue<int> q;
        for (int i=0;i<n;i++) {
            for(auto j:graph[i]){
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        
        for (int i = 0; i <n; i++) {
            if (indegree[i] == 0){
                q.push(i);
                topo.push_back(i);
            }
                
        }

       
        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0){
                    q.push(neighbor);
                    topo.push_back(neighbor);
            }
        }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }
};