class Solution {
public:
    int solve(vector<int> &nums, int sum, int index, vector<vector<int>> &dp){
        if(sum == 0) return 1;

        if(index == nums.size()) return 0;

        if(dp[index][sum] != -1) return dp[index][sum];

        // int not take
        int notTake = solve(nums, sum, index + 1, dp);
        int take = 0;
        if(nums[index] <= sum){
            take = solve(nums, sum - nums[index], index + 1, dp);
        }
        return dp[index][sum] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 == 1) return false;

        vector<vector<int>> dp(n + 1, vector<int> (sum / 2 + 1, -1));
        return solve(nums, sum / 2, 0, dp);
    }
};
