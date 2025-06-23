class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;

        vector<vector<int>> dist(n,vector<int> (n,INT_MAX));
        queue<pair<int,int>> q;
        dist[0][0]=1;
        q.push({0,0});
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={1,0,-1,1,-1,1,0,-1};
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            int d=dist[x][y];
            if(x==n-1 && y==n-1) return d;
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && dist[x][y]+1 < dist[nx][ny]){
                    dist[nx][ny]=dist[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        return -1;
    }
};