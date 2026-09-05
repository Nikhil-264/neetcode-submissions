class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int lo = 0;
        int n = nums.size();
        int hi = n - 1;

        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[lo] <= nums[hi]){
                ans = min(ans, nums[lo]);
                break;
            }else if(nums[lo] <= nums[mid]){
                ans = min(ans, nums[lo]);
                lo = mid + 1;
            }else if(nums[lo] >= nums[mid] and nums[mid] <= nums[hi]){
                ans = min(ans, nums[mid]);
                hi = mid - 1;
            }
        }
        return ans;
    }
};