class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;

        int maxA = INT_MIN;

        while(l < r){
            int len = r - l;

            maxA = max(maxA, len * min(nums[l], nums[r]));

            if(nums[l] < nums[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxA;
    }
};
