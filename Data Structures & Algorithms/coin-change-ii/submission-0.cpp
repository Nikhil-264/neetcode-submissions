class Solution {
public:
    int solve(int amount, int index, vector<vector<int>> &dp, vector<int> &coins){
        if(amount == 0){
            return 1;
        }
        if(index == coins.size()) {
            return 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notTake = solve(amount, index + 1, dp, coins);

        int take = 0;
        if(coins[index] <= amount){
            take = solve(amount - coins[index], index, dp, coins);
        }

        return dp[index][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));

        return solve(amount, 0, dp, coins);
    }
};
