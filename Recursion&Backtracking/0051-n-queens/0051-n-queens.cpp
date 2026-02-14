class Solution {
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, 
               vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
        
        // Base Case: Agar saari columns bhar gayi hain
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            // Check if it's safe to place queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
                
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recursion for next column
                solve(col + 1, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);

                // Backtrack: Reset values
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        
        // Hashing arrays to keep track of safe positions
        vector<int> leftRow(n, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);

        solve(0, n, board, ans, leftRow, upperDiagonal, lowerDiagonal);
        return ans;
    }
};