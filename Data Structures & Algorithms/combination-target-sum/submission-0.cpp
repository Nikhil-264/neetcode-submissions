class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int target, int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == nums.size()){
            return;
        }

        //take the element
        if(nums[index] <= target){
            temp.push_back(nums[index]);
            solve(ans, temp, nums, target - nums[index], index);
            temp.pop_back();
        }

        // not take the element
        solve(ans, temp, nums, target, index + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        int index = 0;

        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, nums, target, 0);
        return ans;
    }
};
