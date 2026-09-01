class Solution {
public:
    void bfs(vector<vector<int>> &vis, vector<vector<char>>& grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            for(auto it : directions){
                int nrow = p.first + it.first;
                int ncol = p.second + it.second;

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and grid[nrow][ncol] == '1' and vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] and grid[i][j] == '1'){
                    islands++;
                    bfs(vis, grid, i, j);
                }
            }
        }

        return islands;
    }
};
