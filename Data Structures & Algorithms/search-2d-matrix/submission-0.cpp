class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // finding row
        int l = 0, r = n - 1;
        int requiredRow = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(matrix[mid][0] <= target and matrix[mid][m - 1] >= target){
                requiredRow = mid;
                break;
            }

            if(matrix[mid][0] > target){
                r = mid - 1;
            }else if(matrix[mid][m - 1] < target){
                l = mid + 1;
            }
        }

        if(requiredRow == -1) return false;

        l = 0, r = m - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(matrix[requiredRow][mid] == target){
                return true;
            }

            if(matrix[requiredRow][mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};
