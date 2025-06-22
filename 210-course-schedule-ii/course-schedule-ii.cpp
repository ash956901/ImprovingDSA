class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        vector<int> indegree(numCourses,0);
        vector<int> topo;
        queue<int> q;

        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        
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
       
        if(topo.size()==numCourses) {
             reverse(topo.begin(),topo.end());
            return topo;}
        topo.clear();
        return topo;

    }
};