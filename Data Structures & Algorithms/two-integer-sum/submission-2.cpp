class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> mp;
        for(int i = 0; i < n; i++){
            mp.push_back({nums[i], i});
        }
        sort(mp.begin(), mp.end());
        vector<int> ans;
        int l = 0, r = n - 1;
        while(l < r){
            if(mp[l].first + mp[r].first == target){
                ans = {mp[l].second, mp[r].second};
                break;
            }else if(mp[l].first + mp[r].first < target){
                l++;
            }else{
                r--;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
