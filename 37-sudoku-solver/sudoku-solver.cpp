class Solution {
public:
    vector<vector<char>> cp;
    bool isSafe(int num, int i, int j, vector<vector<int>>& check) {
        if (check[num][i]) return false;
        if (check[num][9+j]) return false;
        if (check[num][18+((i/3)*3+(j/3))]) return false;
        return true;
    }
    void solve(vector<vector<char>>& board, int i, int j,vector<vector<int>>& check) {
       
        if(i==9){
            //it reached here, means sudoku filled now just copy the array 
            cp=board;
            return;
        }
        if (board[i][j]!='.') {
            int changeCheck=j/9;
            if (!changeCheck) solve(board,i,j+1,check);
            else solve(board,i+1,0,check);
        } 
        else {
            // empty explore all options and backtrack
            for (int k=1;k<=9;k++) {
                if (isSafe(k,i,j,check)) {
                    check[k][i] = 1;
                    check[k][9+j] = 1;
                    check[k][18+((i/3)*3+(j/3))]=1;
                    board[i][j]=(char)'0'+k;
                    int changeCheck=j/9;
                    if (!changeCheck) solve(board,i,j+1,check);
                    else solve(board,i+1,0,check);
                    board[i][j]='.';
                    check[k][i]=0;
                    check[k][9+j]=0;
                    check[k][18+((i/3)*3+(j/3))]=0;
                }
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> check(10, vector<int>(28, 0));
        //mark check for already filled num
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0';
                    check[num][i]=1;
                    check[num][9+j]=1;
                    check[num][18+((i/3)*3+(j/3))]=1;
                }
            }
        }
        solve(board, 0, 0, check);
        board=cp;
    }
};