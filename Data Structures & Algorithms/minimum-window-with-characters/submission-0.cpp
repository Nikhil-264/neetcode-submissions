class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) return "";

        unordered_map<char, int> cntT, window;
        int n = s.size();

        for(char c : t){
            cntT[c]++;
        }

        int have = 0;
        int need = cntT.size();
        pair<int, int> res = {-1, -1};

        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < n; r++){
            char c = s[r];

            window[c]++;

            if(cntT.count(c) and window[c] == cntT[c]){
                have++;
            }

            while(have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if(cntT.count(s[l]) and window[s[l]] < cntT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
