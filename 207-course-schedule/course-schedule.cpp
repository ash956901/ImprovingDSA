class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<int> indegree(numCourses,0);
        vector<int> topo;

        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(!indegree[i]) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();

            for(auto i:adj[node]){
                indegree[i]-=1;
                if(indegree[i]==0) q.push(i);
            }


        }

        return topo.size()==numCourses;

    }
};