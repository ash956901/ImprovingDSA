class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;
        vector<int> indegree(numCourses, 0);
        vector<int> topo;
        queue<int> q;
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

       
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

       
        if (topo.size() == numCourses)
            return topo;

        
        return {};
    }
};
