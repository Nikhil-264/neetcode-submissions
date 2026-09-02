class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> prefix(n + 2, 0);
        vector<int> suffix(n + 2, 0);

        int prefMax = 0;
        for(int i = 1; i <= n; i++){
            prefix[i] = max(prefMax, height[i - 1]);
            prefMax = max(prefMax, height[i - 1]);
        }
        prefix[n + 1] = prefMax;

        int suffMax = 0;
        for(int i = n; i > 0; i--){
            suffix[i] = max(suffMax, height[i - 1]);
            suffMax = max(suffMax, height[i - 1]);
        }
        suffix[0] = suffMax;

        int ans = 0;

        for(int i = 0; i < n; i++){
            ans += max(min(prefix[i], suffix[i + 2]) - height[i], 0);
        }
        return ans;
    }
};
