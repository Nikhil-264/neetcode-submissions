/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> inter;

        for(int i = 0; i < intervals.size(); i++){
            inter.push_back({intervals[i].start, 1});
            inter.push_back({intervals[i].end, -1});
        }

        sort(inter.begin(), inter.end());

        int check = 0;
        int maxAns = 0;

        for(int i = 0; i < inter.size(); i++){
            if(inter[i].second == 1){
                check++;
            }else{
                check--;
            }
            maxAns = max(maxAns, check);
        }
        return maxAns;
    }
};
