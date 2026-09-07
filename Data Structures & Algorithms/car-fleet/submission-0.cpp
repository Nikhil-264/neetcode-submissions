class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            mp.push_back({position[i], speed[i]});
        }

        sort(mp.rbegin(), mp.rend());

        stack<pair<int, int>> st;
        int ct = 1;
        st.push(mp[0]);
        for(int i = 1; i < n; i++){
            double timeOfLead = (target - st.top().first) / (double)(st.top().second);

            double timeOfCurr = (target - mp[i].first) / (double)(mp[i].second);

            if(timeOfCurr > timeOfLead){
                st.push(mp[i]);
                ct++;
            }
        }
        return ct;
    }
};
