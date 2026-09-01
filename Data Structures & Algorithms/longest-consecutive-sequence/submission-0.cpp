class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 0;

        unordered_set<int> numSet(nums.begin(), nums.end());

        for(int num : nums){
            if(numSet.find(num - 1) == numSet.end()){
                int currentStreak = 1;
                int currNum = num;

                while(numSet.find(currNum + 1) != numSet.end()){
                    currentStreak++;
                    currNum++;
                }
                longest = max(longest, currentStreak);
            }
        }
        return longest;
    }
};
