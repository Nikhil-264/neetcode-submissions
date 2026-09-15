class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<int> prev(m + 1, 1);
        
        for(int i = 1; i < n; i++){
            vector<int> curr(m + 1, 0);
            curr[0] = 1;
            for(int j = 1; j <= m; j++){
                curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }

        return prev[m-1];
    }
};
