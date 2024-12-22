class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        vector<int>ans(q.size(),-1);
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<>>pq;
        vector<vector<pair<int,int>>>query(h.size());

        for(int i=0;i<q.size();i++){
            int a=q[i][0];
            int b=q[i][1];

            if(a>b)swap(a,b);

            if(a==b)ans[i]=a;
            else if(h[b]>h[a])ans[i]=b;
            else{
                query[b].push_back({max(h[a],h[b]),i});
            }
        }
        for(int i=0;i<h.size();i++){
            while(!pq.empty()&&pq.top().first<h[i]){
                ans[pq.top().second]=i;
                pq.pop();
            }
            for(int j=0;j<query[i].size();j++){
                pq.push({query[i][j].first,query[i][j].second});
            }
        }
        return ans;
    }
        
};