class Solution {
public:
    
    int countSubstrings(string s) {
        int n = s.size();

        int ans = 0;

        for(int i = 0; i < n; i++){
            // odd length ones;
            int left = i, right = i;

            while(left >= 0 and right < n and s[left] == s[right]){
                left--;
                right++;
            }

            int curLen = right - left - 1;
            ans += curLen / 2 + 1;

            // / even length ones
            left = i - 1, right = i;
            while(left >= 0 and right < n and s[left] == s[right]){
                left--;
                right++;
            }

            curLen = right - left - 1;
            ans += curLen / 2;
        }
        return ans;
    }
};
