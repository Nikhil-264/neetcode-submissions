class Solution {
public:
    int solve(vector<int> &coins, int amount, int index, vector<vector<int>> &dp){
        if(index == 0){
            if(amount % coins[index] == 0){
                return amount / coins[index];
            }else{
                return 1e9;
            }
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        // take the coin
        int take = 1e9;
        if(coins[index] <= amount){
            take = 1 + solve(coins, amount - coins[index], index, dp);
        }
        int notTake = solve(coins, amount, index - 1, dp);

        return dp[index][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int> (amount + 1, -1));

        int ans = solve(coins, amount, n - 1, dp);

        if(ans == 1e9){
            return -1;
        }
        return ans;
    }
};
