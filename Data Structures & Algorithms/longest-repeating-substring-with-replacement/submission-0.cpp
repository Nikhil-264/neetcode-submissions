class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> ct(26, 0);
        int l = 0;
        int n = s.size();

        int maxi = 0;
        int ans = 0;

        for(int r = 0; r < n; r++){
            ct[s[r] - 'A']++;
            maxi = max(maxi, ct[s[r] - 'A']);
            if(r - l + 1 - maxi > k){
                ct[s[l] - 'A']--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
