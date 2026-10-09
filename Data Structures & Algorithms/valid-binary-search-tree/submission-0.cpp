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
    bool f(TreeNode* root, int leftLimit, int rightLimit){
        if(!root) return true;

        return root->val > leftLimit and root->val < rightLimit and f(root->left, leftLimit, root->val) and f(root->right, root->val, rightLimit);
    }
    bool isValidBST(TreeNode* root) {
        return f(root, INT_MIN, INT_MAX);
    }
};
