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
    pair<bool, int> height(TreeNode* root){
        if(!root) return {true, 0};

        pair<bool, int> left, right;

        left = height(root->left);
        right = height(root->right);

        return {left.first && right.first && (abs(left.second - right.second) <= 1), 1 + max(left.second, right.second)};
    }
    bool isBalanced(TreeNode* root) {
        auto it = height(root);
        return it.first;
    }
};
