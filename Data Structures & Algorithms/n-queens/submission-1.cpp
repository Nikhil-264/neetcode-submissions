class Solution {
public:
    void solve(int row, int n, vector<int> &column, vector<int> &diag1, vector<int> &diag2, vector<string> &board, vector<vector<string>> &ans){
        if(n == row){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(column[col] and diag1[col + row] and diag2[row - col + n]){
                column[col] = 0;
                diag1[row + col] = 0;
                diag2[row - col + n] = 0;
                board[row][col] = 'Q';

                solve(row + 1, n, column, diag1, diag2, board, ans);

                column[col] = 1;
                diag1[row + col] = 1;
                diag2[row - col + n] = 1;
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> columnAva(n, 1);

        vector<int> diag1(2 * n, 1); // is available top right to left bottom
        vector<int> diag2(2 * n, 1); //top left to right bottom

        solve(0, n, columnAva, diag1, diag2, board, ans);
        return ans;
    }
};
