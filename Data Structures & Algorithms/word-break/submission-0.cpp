class Solution {
public:
    bool dfs(string &s, vector<string> &wordDict, unordered_map<int, int> &mp, int index){
        if(mp.find(index) != mp.end()) return mp[index];

        for(string w : wordDict){
            if(index + w.size() <= s.size() and s.substr(index, w.size()) == w){
                if(dfs(s, wordDict, mp, index + w.size())){
                    mp[index] = 1;
                    return true;
                }
            }
        }
        
        mp[index] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, int> mp;
        mp[s.size()] = 1;
        return dfs(s, wordDict, mp, 0);;
    }
};
