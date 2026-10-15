class Solution {
public:
    int dfs(vector<vector<int>> &mat, int i, int j, int &n, int &m, vector<int> &dir, vector<vector<int>> &dp){
        if(dp[i][j] != 0) return dp[i][j];
        int most = 0;
        for(int d = 0; d < 4; d++){
            int newI = i + dir[d];
            int newJ = j + dir[d + 1];

            if(newI >= 0 and newI < n and newJ >= 0 and newJ < m and mat[newI][newJ] > mat[i][j]){
                most = max(most, dfs(mat, newI, newJ, n, m, dir, dp));
            }
        }
        return dp[i][j] = most + 1;
    }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 1;

        vector<vector<int>> dp(n, vector<int> (m, 0));
        vector<int> dir = {-1, 0, 1, 0, -1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, dfs(mat, i, j, n, m, dir, dp));
            }
        }
        return ans;
    }
};
