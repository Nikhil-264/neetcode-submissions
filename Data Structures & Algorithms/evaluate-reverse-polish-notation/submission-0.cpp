class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        int val = 0;
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop();

                if(tokens[i] == "+"){
                    st.push(first + second);
                }else if(tokens[i] == "-"){
                    st.push(first - second);
                }else if(tokens[i] == "*"){
                    st.push(first * second);
                }else if(tokens[i] == "/"){
                    st.push(first / second);
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
