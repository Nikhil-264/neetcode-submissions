class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string, int>> a;
        int n = strs.size();

        for(int i = 0; i < n; i++){
            string curr = strs[i];
            sort(curr.begin(), curr.end());
            a.push_back({curr, i});
        }

        sort(a.begin(), a.end());
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back(strs[a[0].second]);

        for(int i = 1; i < n; i++){
            if(a[i].first == a[i - 1].first){
                temp.push_back(strs[a[i].second]);
            }else{
                ans.push_back(temp);
                temp = {};
                temp.push_back(strs[a[i].second]);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
