class Solution {
public:
    void buildTree(int left, int right, int index, vector<int> &nums, vector<int> &segTree){
        if(left == right){
            segTree[index] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;

        buildTree(left, mid, 2 * index + 1, nums, segTree);
        buildTree(mid + 1, right, 2 * index + 2, nums, segTree);

        segTree[index] = max(segTree[2 * index + 1], segTree[2 * index + 2]);
    }

    int query(int left, int right, int l, int r, int index, vector<int> &nums, vector<int> &segTree){
        // conplete overlap
        if(r < left or l > right){
            return INT_MIN;
        }

        if(l <= left and r >= right){
            return segTree[index];
        }
        //

        int mid = left + (right - left) / 2;

        int leftMax = query(left, mid, l, r, 2 * index + 1, nums, segTree);
        int rightMax = query(mid + 1, right, l, r, 2 * index + 2, nums, segTree);

        return max(leftMax, rightMax);
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return {};

        vector<int> segTree(4 * n + 1);
        buildTree(0, n - 1, 0, nums, segTree);
        vector<int> ans;
        for(int l = 0; l <= n - k; l++){
            int maxi = query(0, n - 1, l, l + k - 1, 0, nums, segTree);
            ans.push_back(maxi);
        }
        return ans;
    }
};
