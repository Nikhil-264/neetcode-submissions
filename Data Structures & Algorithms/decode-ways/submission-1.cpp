class Solution {
public:
    int solve(string &s, int &n, vector<int> &dp, int index){
        if(index == n) return 1;

        if(s[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        int ways = solve(s, n, dp, index + 1);

        if(index + 1 < n){
            int twoDigit = (s[index] - '0') * 10 + (s[index + 1] - '0');
            if(twoDigit >= 10 and twoDigit <= 26){
                ways += solve(s, n, dp, index + 2);
            }
        }

        return dp[index] = ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, n, dp, 0);
    }
};
