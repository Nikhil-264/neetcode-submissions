class Solution {
public:
    void solve(vector<int> &nums, set<vector<int>> &st, vector<int> &temp, int index){
        if(index == nums.size()){
            st.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        solve(nums, st, temp, index + 1);
        temp.pop_back();
        solve(nums, st, temp, index + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums, st, temp, 0);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
