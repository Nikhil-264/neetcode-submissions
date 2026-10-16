class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int sum = 0;
        bool pos = false;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(nums[i] >= 0) pos = true;
            ans = max(ans, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(!pos) return *max_element(nums.begin(), nums.end());
        return ans;
    }
};
