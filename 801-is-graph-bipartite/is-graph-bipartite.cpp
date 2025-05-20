class Solution {
public:
    bool ans=true;
    void bfs(int i,vector<vector<int>>& graph,vector<int> &color){
        queue<int> q;
        q.push(i);
        color[i]=1;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
           
            for(auto j:graph[node]){
                if(!color[j]){
                        color[j]=color[node]==1?(2):(1);
                        q.push(j);
                }
                else if(color[j]==color[node]){
                    ans=false;
                    break;
                }
            }


        }

    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size()+1,0);
        for(int i=0;i<graph.size();i++){
            if(!color[i]){
                bfs(i,graph,color);
            }
        }

        return ans;
    }
};