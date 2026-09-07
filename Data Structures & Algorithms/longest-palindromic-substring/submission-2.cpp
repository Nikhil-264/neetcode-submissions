class Solution {
public:
    string longestPalindrome(string s) {
        int resIndex = 0;
        int resLength = 0;

        int n = s.size();

        vector<vector<int>> dp(n, vector<int> (n, 0));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j] and (j - i <= 2 or dp[i + 1][j - 1])){
                    dp[i][j] = 1;
                    if(resLength < (j - i + 1)){
                        resIndex = i;
                        resLength = j - i + 1;
                    }
                }
            }
        }
        return s.substr(resIndex, resLength);
    }
};
