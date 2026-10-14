class Solution {
public:
    int leastInterval(vector<char>& tasks, int idle) {
        unordered_map<char, int> mp;
        int n = tasks.size();
        int maxFreq = 0;
        for(int i = 0; i < n; i++){
            mp[tasks[i]]++;
            maxFreq = max(maxFreq, mp[tasks[i]]);
        }

        int maxFreqCount = 0;
        for(auto &pair : mp){
            if(pair.second == maxFreq){
                maxFreqCount++;
            }
        }

        int ans = (maxFreq - 1) * (idle + 1) + maxFreqCount;
        return max((int)tasks.size(), ans);

    }
};