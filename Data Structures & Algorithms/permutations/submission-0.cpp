class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int index){
        // index is the index of taken element from nums

        if(index == temp.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = index; i < temp.size(); i++){
            swap(temp[i], temp[index]);
            solve(ans, temp, index + 1);
            swap(temp[i], temp[index]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp = nums;
        solve(ans, temp, 0);
        return ans;
    }
};
