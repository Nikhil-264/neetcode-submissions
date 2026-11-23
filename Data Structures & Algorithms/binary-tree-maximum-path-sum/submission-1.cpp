/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root, int &ans, int & bigNode){
        if(!root) return 0;
        if(root->val > bigNode) bigNode = root->val;

        int leftSum = solve(root->left, ans, bigNode);
        int rightSum = solve(root->right, ans, bigNode);

        ans = max({ans, leftSum + root->val + rightSum});

        return max({0, leftSum + root->val, rightSum + root->val});
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int bigNode = INT_MIN;
        int sum = solve(root, ans, bigNode);
        if(bigNode < 0) return bigNode;
        return ans;
    }
};
