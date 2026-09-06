class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);

        stack<pair<int, int>> st;

        st.push({0, temp[0]});

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push({i, temp[i]});
                continue;
            }

            while(!st.empty() and temp[i] > st.top().second){
                ans[st.top().first] = i - st.top().first;
                st.pop();
            }

            st.push({i, temp[i]});
        }
        return ans;
    }
};
