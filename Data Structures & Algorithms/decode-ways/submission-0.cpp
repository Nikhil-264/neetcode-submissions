class Solution {
public:
    int solve(unordered_map<string, char> &mp, string &s, int &n, int index, vector<int> &dp){
        if(index > n - 1){
            return 1;
        }

        if(dp[index] != -1) return dp[index];

        // one letter
        string temp = string(1, s[index]);
        if(mp.find(temp) == mp.end()){
            return 0;
        }
        int oneLetter = solve(mp, s, n, index + 1, dp);
        // two letter

        int twoLetter = 0;
        if(index + 1 < n){
            temp += string(1, s[index + 1]);
            if(mp.find(temp) != mp.end()){
                twoLetter = solve(mp, s, n, index + 2, dp);
            }
        }

        return dp[index] = oneLetter + twoLetter;
    }
    int numDecodings(string s) {
        int n = s.size();

        unordered_map<string, char> mp;
        mp["1"] = 'A';
        mp["2"] = 'B';
        mp["3"] = 'C';
        mp["4"] = 'D';
        mp["5"] = 'E';
        mp["6"] = 'F';
        mp["7"] = 'G';
        mp["8"] = 'H';
        mp["9"] = 'I';
        mp["10"] = 'J';
        mp["11"] = 'K';
        mp["12"] = 'L';
        mp["13"] = 'M';
        mp["14"] = 'N';
        mp["15"] = ')';
        mp["16"] = 'P';
        mp["17"] = 'Q';
        mp["18"] = 'R';
        mp["19"] = 'S';
        mp["20"] = 'T';
        mp["21"] = 'U';
        mp["22"] = 'V';
        mp["23"] = 'W';
        mp["24"] = 'X';
        mp["25"] = 'Y';
        mp["26"] = 'Z';

        vector<int> dp(n + 1, -1);
        return solve(mp, s, n, 0, dp);

    }
};
