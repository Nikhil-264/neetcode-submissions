class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &grid, vector<int> &dir, vector<vector<int>> &vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        for(int i = 0; i < 4; i++){
            int nRow = row + dir[i];
            int nCol = col + dir[i + 1];

            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and grid[nRow][nCol] == 'O'){
                dfs(nRow, nCol, grid, dir, vis);
            }
        }
    }
    void solve(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            if(!vis[i][0] and grid[i][0] == 'O'){
                dfs(i, 0, grid, dir, vis);
            }
            if(!vis[i][m - 1] and grid[i][m - 1] == 'O'){
                dfs(i, m - 1, grid, dir, vis);
            }
        }

        for(int j = 1; j < m - 1; j++){
            if(!vis[0][j] and grid[0][j] == 'O'){
                dfs(0, j, grid, dir, vis);
            }
            if(!vis[n - 1][j] and grid[n - 1][j] == 'O'){
                dfs(n - 1, j, grid, dir, vis);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    grid[i][j] = 'X';
                }
            }
        }
    }
};
