class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(n - 1, n, board, res);
        return res;
    }

private:
    
    bool isSafe(int row, int col, const vector<string>& board, int n) {
      
        for (int j = col + 1; j < n; ++j)
            if (board[row][j] == 'Q') return false;

      
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q') return false;

     
        for (int i = row + 1, j = col + 1; i < n && j < n; ++i, ++j)
            if (board[i][j] == 'Q') return false;

        return true;
    }

    void backtrack(int col, int n,
                   vector<string>& board,
                   vector<vector<string>>& res) {
        if (col < 0) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            if (!isSafe(row, col, board, n)) continue;
            board[row][col] = 'Q';
            backtrack(col - 1, n, board, res);
            board[row][col] = '.';
        }
    }
};
