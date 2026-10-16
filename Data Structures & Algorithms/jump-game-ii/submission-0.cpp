class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1e5);
        dp[0] = 0;
        
        for(int i = 0; i < n; i++){
            int jumps = nums[i];
            for(int j = 1; j <= jumps and i + j < n; j++){
                if(1 + dp[i] < dp[i + j]){
                    dp[i + j] = 1 + dp[i];
                }
            }
        }
        return dp[n - 1];
    }
};
