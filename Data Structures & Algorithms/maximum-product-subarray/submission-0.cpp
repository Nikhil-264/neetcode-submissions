class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        long long pro = 1;
        long long maxFromStart = INT_MIN;
        long long maxFromEnd = INT_MIN;
        
        for(int i = 0; i < n; i++){
            pro = nums[i] * pro;

            if(pro > maxFromStart) maxFromStart = pro;
            if(pro == 0) pro = 1;
        }
        pro = 1;
        for(int i = n - 1; i >= 0; i--){
            pro = nums[i] * pro;

            if(pro > maxFromEnd) maxFromEnd = pro;
            if(pro == 0) pro = 1;
        }
        return max(maxFromEnd, maxFromStart);
    }
};
