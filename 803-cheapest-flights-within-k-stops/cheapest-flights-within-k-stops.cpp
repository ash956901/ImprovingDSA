class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

      
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();

            if (city == dst) return cost;
            if (stops > k) continue;

            for (auto& [nei, price] : adj[city]) {
                int newCost = cost + price;
                if (newCost < dist[nei][stops + 1]) {
                    dist[nei][stops + 1] = newCost;
                    pq.push({newCost, nei, stops + 1});
                }
            }
        }

        return -1;
    }
};
