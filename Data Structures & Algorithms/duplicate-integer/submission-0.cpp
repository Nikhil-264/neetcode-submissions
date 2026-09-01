class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()) return true;

            mp[nums[i]] = 1;
        }
        return false;
    }
};