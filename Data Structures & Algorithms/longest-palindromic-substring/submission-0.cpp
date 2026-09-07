class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int maxLen = 1;
        int start = 0;

        for(int i = 0; i < n; i++){
            // expanding as i as centre
            int left = i, right = i;
            while(left >= 0 and right < n and s[left] == s[right]){
                left--;
                right++;
            }
            int curLen = right - left - 1;
            if(curLen > maxLen){
                maxLen = curLen;
                start = left + 1;
            }

            // expanding as i and i - 1 as centre
            left = i - 1, right = i;
            while(left >= 0 and right < n and s[left] == s[right]){
                left--;
                right++;
            }
            curLen = right - left - 1;
            if(curLen > maxLen){
                maxLen = curLen;
                start = left + 1;
            }
        }
        return s.substr(start, maxLen);
    }
};
