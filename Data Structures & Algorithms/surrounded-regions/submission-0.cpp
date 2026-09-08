class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<string>> str(n, vector<string> (m, ""));

        vector<vector<int>> vis(n, vector<int> (m, 0));
        // for altantic
        queue<pair<int, pair<int, int>>> q;
        //value, row, col

        for(int i = 0; i < n; i++){
            if(vis[i][m - 1] == 0){
                q.push({heights[i][m - 1], {i, m - 1}});
                vis[i][m - 1] = 1;
            }
        }
        for(int j = 0; j < m; j++){
            if(vis[n - 1][j] == 0){
                q.push({heights[n - 1][j], {n - 1, j}});
                vis[n - 1][j] = 1;
            }
        }

        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int value = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            str[row][col] += "a";

            for(auto it : dir){
                int nrow = row + it.first;
                int ncol = col + it.second;

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m){
                    if(heights[nrow][ncol] >= value and vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({heights[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vis[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            if(vis[i][0] == 0){
                q.push({heights[i][0], {i, 0}});
                vis[i][0] = 1;
            }
        }
        for(int j = 0; j < m; j++){
            if(vis[0][j] == 0){
                q.push({heights[0][j], {0, j}});
                vis[0][j] = 1;
            }
        }

        while(!q.empty()){
            int value = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            str[row][col] += "p";

            for(auto it : dir){
                int nrow = row + it.first;
                int ncol = col + it.second;

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m){
                    if(heights[nrow][ncol] >= value and vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = 1;
                        q.push({heights[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(str[i][j].size() == 2){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};