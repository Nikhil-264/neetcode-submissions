class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int n = grid.size();
        int m = grid[0].size();

        int originalCt = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    originalCt++;
                }else if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        int t = 0;
        while(!q.empty()){
            int sz = q.size();
            t++;
            for(int i = 0; i < sz; i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto it : dir){
                    int nRow = row + it.first;
                    int nCol = col + it.second;

                    if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and grid[nRow][nCol] == 1){
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    }
                }
            }
        }

        int currCount = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) currCount++;
            }
        }

        if(currCount > 0) return -1;

        return max(t - 1, 0);
    }
};