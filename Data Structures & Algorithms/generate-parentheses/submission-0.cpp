class Solution {
public:
    void solve(vector<string> &ans, string & temp, int start, int end){
        if(end == 0 and start == 0){
            ans.push_back(temp);
            return;
        }

        if(start == end){
            temp.push_back('(');
            solve(ans, temp, start - 1, end);
            temp.pop_back();
        }
        if(start != 0 and start < end){
            temp.push_back('(');
            solve(ans, temp, start - 1, end);
            temp.pop_back();
            temp.push_back(')');
            solve(ans, temp, start, end - 1);
            temp.pop_back();
        }

        if(start == 0){
            temp.push_back(')');
            solve(ans, temp, start, end - 1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int start = n;
        int end = n;
        vector<string> ans;
        string temp = "";
        solve(ans, temp, start, end);
        return ans;
    }
};
