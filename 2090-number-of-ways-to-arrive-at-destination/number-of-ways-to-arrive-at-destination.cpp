#define MOD 1000000007
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<roads.size();i++){
           int u = roads[i][0], v = roads[i][1], t = roads[i][2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);

        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            auto [currTime,u]=pq.top();
            pq.pop();

            if(currTime>dist[u]) continue;

            for(auto&[neigh,time]:adj[u]){
                if(currTime+time<dist[neigh]){
                    dist[neigh]=currTime+time;
                    ways[neigh]=ways[u];
                    pq.push({dist[neigh],neigh});
                }
                else if(currTime+time==dist[neigh]){
                    ways[neigh]=(ways[u]+ways[neigh])%MOD;
                }
            }

        }

        return ways[n-1];
    }
};