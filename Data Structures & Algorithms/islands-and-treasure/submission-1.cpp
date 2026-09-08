class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<int> dir = {-1, 0, 1, 0, -1};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({{i, j}, 0});
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + dir[i];
                int nCol = col + dir[i + 1];

                if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and grid[nRow][nCol] == 2147483647){
                    grid[nRow][nCol] = dist + 1;
                    q.push({{nRow, nCol}, dist + 1});
                }
            }
        }
    }
};
