class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((i==0 || mat[i][j] > mat[i-1][j]) &&
                (i==r-1 || mat[i][j] > mat[i+1][j]) &&
                (j==0 || mat[i][j] > mat[i][j-1]) &&
                (j==c-1 || mat[i][j] > mat[i][j+1])){
                    return {i,j};
                }
                
                
            }
        }
        return {-1,-1};
    }
};