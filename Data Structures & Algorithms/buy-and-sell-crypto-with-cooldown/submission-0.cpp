class Solution {
public:
    int solve(vector<vector<int>> &dp, vector<int> &prices, int index, int canBuy){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][canBuy] != -1) return dp[index][canBuy];

        if(canBuy){
            int take = - prices[index] + solve(dp, prices, index + 1, 1 - canBuy);
            int notTake = solve(dp, prices, index + 1, canBuy);

            dp[index][canBuy] = max(take, notTake);
        }else{
            int sell = prices[index] + solve(dp, prices, index + 2, 1 - canBuy);
            int notSell = solve(dp, prices, index + 1, canBuy);
            dp[index][canBuy] = max(sell, notSell);
        }

        return dp[index][canBuy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        int canBuy = 1;

        return solve(dp, prices, 0, canBuy);
    }
};
