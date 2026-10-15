class Solution {
public:
    int solve(int index, int total, int target,  vector<int> &nums, vector<vector<int>> &dp, long long &totalSum){
        if(index == nums.size()){
            return total == target;
        }

        if(dp[index][total + totalSum] != INT_MIN) return dp[index][total + totalSum];

        int adding = solve(index + 1, total - nums[index], target, nums, dp, totalSum);
        int subing = solve(index + 1, total + nums[index], target, nums, dp, totalSum);

        return dp[index][total + totalSum] = adding + subing;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int> (2 * totalSum + 1, INT_MIN));

        return solve(0, 0, target, nums, dp, totalSum);
    }
};
