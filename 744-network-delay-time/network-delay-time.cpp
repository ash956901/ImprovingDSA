class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        vector<int> dist(n+1,INT_MAX);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }   

        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto [time,node]=pq.top();
            pq.pop();

            if(time>dist[node]) continue;

            for(auto [neigh,time]:adj[node]){
                if(dist[node]+ time <dist[neigh]){
                    dist[neigh]=dist[node]+time;
                    pq.push({dist[neigh],neigh});
                }
            }

        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            if(i!=k){maxi=max(maxi,dist[i]);}
        }
        return maxi;
    }
};