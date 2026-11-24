class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dir = {-1, 0, 1, 0, -1};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));

        pq.push({grid[0][0], 0, 0});

        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            auto [time, row, col] = pq.top();
            pq.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + dir[i];
                int nCol = col + dir[i + 1];

                if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m){
                    if(dist[nRow][nCol] > max(grid[nRow][nCol], dist[row][col])){
                        dist[nRow][nCol] = max(grid[nRow][nCol], dist[row][col]);
                        pq.push({dist[nRow][nCol], nRow, nCol});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
