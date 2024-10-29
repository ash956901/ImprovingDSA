class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<int>> &dp){
        if(i>=m || j>=n || i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int updiag=0;
        int mid=0;
        int lowdiag=0;
        int curr_cell=grid[i][j];
        //row-1,col+1
        if(i-1>=0 && j+1 <n){
           //check if bigger than current cell
            if(grid[i-1][j+1]>curr_cell){
                updiag=1+solve(grid,m,n,i-1,j+1,dp);
            }
        }
        //row,col+1
        if(j+1 <n){
           //check if bigger than current cell
            if(grid[i][j+1]>curr_cell){
                mid=1+solve(grid,m,n,i,j+1,dp);
            }
        }
        //row+1,col+1
        if(i+1<m && j+1 <n){
           //check if bigger than current cell
            if(grid[i+1][j+1]>curr_cell){
                lowdiag=1+solve(grid,m,n,i+1,j+1,dp);
            }
        }


        int ans=max(updiag,max(mid,lowdiag));

        dp[i][j]=ans;

        return ans;

    }
    int maxMoves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            maxi=max(maxi,solve(grid,m,n,i,0,dp));
        }

        return maxi;
    }
};