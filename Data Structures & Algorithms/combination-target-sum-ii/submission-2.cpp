class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int target, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            if(i > index and nums[i] == nums[i - 1]) continue;

            if(nums[i] > target) break;

            if(nums[i] <= target){
                temp.push_back(nums[i]);
                solve(ans, temp, nums, target - nums[i], i + 1);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, temp, candidates, target, 0);
        return ans;
    }
};
