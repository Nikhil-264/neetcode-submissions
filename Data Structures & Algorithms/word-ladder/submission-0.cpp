class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        int m = endWord.size();

        if(n != m) return 0;

        unordered_map<string, int> mp;
        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]]++;
        }

        if(!mp.count(endWord)) return 0;

        if(beginWord == endWord) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty()){
            string currWord = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(currWord == endWord) return steps;

            for(int i = 0; i < n; i++){
                char original = currWord[i];
                for(char c = 'a'; c <= 'z'; c++){
                    if(c == original) continue;
                    currWord[i] = c;
                    if(mp.count(currWord)){
                        q.push({currWord, steps + 1});
                        mp.erase(currWord);
                    }
                }
                currWord[i] = original;
            }
        }
        return 0;
    }
};
