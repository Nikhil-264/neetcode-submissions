class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &sz, vector<int> &dir, int &n, int &m){
        vis[row][col] = 1;
        sz++;
        for(int i = 0; i < 4; i++){
            int nRow = row + dir[i];
            int nCol = col + dir[i + 1];

            if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and grid[nRow][nCol] == 1){
                dfs(nRow, nCol, grid, vis, sz, dir, n, m);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int> (m, 0));

        int maxAns = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int sz = 0;
                if(!vis[i][j] and grid[i][j] == 1){
                    dfs(i, j, grid, vis, sz, dir, n, m);
                }
                maxAns = max(maxAns, sz);
            }
        }
        return maxAns;
    }
};
