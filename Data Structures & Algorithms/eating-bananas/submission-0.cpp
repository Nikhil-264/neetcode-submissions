class Solution {
public:
    int solve(int mid, vector<int> &piles){
        int n = piles.size();
        int hrs = 0;

        for(int i = 0; i < n; i++){
            if(piles[i] % mid == 0){
                hrs += piles[i] / mid;
            }else{
                hrs += piles[i] / mid + 1;
            }
        }
        return hrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;

            int hrs = solve(mid, piles);

            if(hrs <= h){
                // low = mid + 1;
                high = mid - 1;
            }else{
                // high = mid - 1;
                low = mid + 1;
            }
        }
        return low;
    }
};
