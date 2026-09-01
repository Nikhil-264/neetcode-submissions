class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;

            while(l < r){
                if(nums[i] + nums[l] + nums[r] == 0){
                    ans.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(nums[i] + nums[l] + nums[r] < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};
