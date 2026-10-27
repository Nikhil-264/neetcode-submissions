class Solution {
public:
    bool dfs(int i, int j, int index, vector<int> &dir, vector<vector<char>>&board, string &word, vector<vector<int>> &visited, int &n, int &m, int &len){

        if(board[i][j] != word[index]) return false;
        if(index == len - 1) return true;
        visited[i][j] = 1;

        for(int d = 0; d < 4; d++){
            int nRow = i + dir[d];
            int nCol = j + dir[d + 1];

            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !visited[nRow][nCol]){
                if(dfs(nRow, nCol, index + 1, dir, board, word, visited, n, m, len)){
                    visited[i][j] = 0;
                    return true;
                }
            }
        }
        visited[i][j] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int len = word.size();

        vector<vector<int>> visited(n, vector<int> (m, 0));
        vector<int> dir = {-1, 0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dfs(i, j, 0, dir, board, word, visited, n, m, len)) return true;
            }
        }
        return false;
    }
};
