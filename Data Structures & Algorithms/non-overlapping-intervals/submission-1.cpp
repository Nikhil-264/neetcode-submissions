class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int ct = 0;
        int n = intervals.size();
        
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i = 1; i < n; i++){
            bool alreadyChanged = false;
            if(intervals[i][0] < end){
                if(end > intervals[i][1]){
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
                alreadyChanged = true;
                ct++;
            }
            if(!alreadyChanged){
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }   
        return ct;
    }
};
