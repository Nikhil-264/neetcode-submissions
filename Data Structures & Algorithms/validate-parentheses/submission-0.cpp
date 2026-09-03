class Solution {
public:
    bool isSame(char &open, char &close){
        if(open == '{' and close == '}') return true;
        if(open == '(' and close == ')') return true;
        if(open == '[' and close == ']') return true;
        return false;
    }
    bool isClosing(char &c){
        return (c == '}' or c == ']' or c == ')');
    }
    bool isValid(string s) {
        stack<char> q;

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(!isClosing(s[i])){
                q.push(s[i]);
            }
            else if(q.empty() and isClosing(s[i])){
                return false;
            }
            else if(!q.empty() and isClosing(s[i])){
                if(isSame(q.top(), s[i])){
                    q.pop();
                }else{
                    return false;
                }
            }
        }
        if(!q.empty()) return false;
        return true;
    }
};
