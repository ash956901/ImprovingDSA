class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp,int &sum){
        if(i>=matrix.size() || j>=matrix[0].size()){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int right=solve(i,j+1,matrix,dp,sum);
        int diag=solve(i+1,j+1,matrix,dp,sum);
        int down=solve(i+1,j,matrix,dp,sum);

        if(matrix[i][j]==1){
            int ans=1+ min(right,min(diag,down));
            sum+=ans;
            return dp[i][j]= ans;

        }
        else{
            return dp[i][j]=0;
        }
    }
    int countSquares(vector<vector<int>>& matrix) {
        int sum=0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        solve(0,0,matrix,dp,sum);
        return sum;
    }
};