class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
       
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>> dist(row,vector<int> (col,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        dist[0][0]=0;
        pq.push({0,0,0});
        vector<int> dx={-1,0,0,1};
        vector<int> dy={0,-1,1,0};
        while(!pq.empty()){
            auto [effort,x,y]=pq.top();pq.pop();
            if(x==row-1 && y==col-1) return effort;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<row && ny<col && max(effort,abs(heights[x][y]-heights[nx][ny])) < dist[nx][ny]){
                    int newEffort=max(effort,abs(heights[x][y]-heights[nx][ny]));               
                    dist[nx][ny]=newEffort;
                    pq.push({newEffort,nx,ny});
                }
            }
        }

        return -1;

    }
};