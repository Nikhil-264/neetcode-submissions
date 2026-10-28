class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> p;
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    p.push_back({i, j});
                }
            }
        }

        for(int i = 0; i < p.size(); i++){
            int row = p[i].first;
            int col = p[i].second;

            for(int j = 0; j < n; j++){
                matrix[j][col] = 0;
            }
            for(int j = 0; j < m; j++){
                matrix[row][j] = 0;
            }
        }
    }
};
