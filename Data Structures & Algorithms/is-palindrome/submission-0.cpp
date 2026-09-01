class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char c : s){
            if((c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z') or (c >= '0' and c <= '9')){
                temp.push_back(tolower(c));
            }
        }
        int n = temp.size();
        for(int i = 0; i < n/2; i++){
            if(temp[i] != temp[n - 1 - i]) return false;
        }
        return true;
    }
};
