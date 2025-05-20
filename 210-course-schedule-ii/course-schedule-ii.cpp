class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }

        vector<int> indegree(numCourses+1,0);
        
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push({i});
            }
        }   
        vector<int> ans;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
      
            ans.push_back(front);

            for(auto i:adj[front]){
                if(--indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;

    }
};