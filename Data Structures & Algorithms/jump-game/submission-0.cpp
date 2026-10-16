class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxTill = 0;
        for(int i = 0; i < n; i++){
            if(i > maxTill) return false;

            maxTill = max(maxTill, nums[i] + i);
        }
        return true;
    }
};
