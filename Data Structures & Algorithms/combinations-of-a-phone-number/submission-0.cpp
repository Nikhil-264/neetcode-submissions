class Solution {
public:
    void solve(string &temp, vector<string> &str, string &digits, int index, vector<string> &ans, int n){
        if(index == n){
            ans.push_back(temp);
            return;
        } 

        for(char it : str[digits[index] - '0']){
            temp.push_back(it);
            solve(temp, str, digits, index + 1, ans, n);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.size();
        if(n == 0) return {};
        vector<string> str(10);
        str[2] = "abc";
        str[3] = "def";
        str[4] = "ghi";
        str[5] = "jkl";
        str[6] = "mno";
        str[7] = "pqrs";
        str[8] = "tuv";
        str[9] = "wxyz";
        string temp = "";
        solve(temp, str, digits, 0, ans, n);
        return ans;
    }
};
