class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1; i < n; i++){
            if(ans.back()[1] >= intervals[i][0] and ans.back()[1] < intervals[i][1]){
                ans.back()[1] = intervals[i][1];
            }else if(ans.back()[1] < intervals[i][0]){
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
