class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        vector<int> ct(128, 0);
        int ans = 0;

        for(int i = 0; i < n; i++){
            ct[s[i] - ' ']++;

            while(ct[s[i] - ' '] > 1){
                ct[s[l] - ' ']--;
                l++;
            }
            ans = max(i - l + 1, ans);
        }
        return ans;
    }
};
