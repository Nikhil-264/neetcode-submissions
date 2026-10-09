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
    void f(TreeNode* root, int maxTill, int &ans){
        if(!root) return;

        if(root->val >= maxTill){
            ans++;
            maxTill = root->val;
        }

        f(root->left, maxTill, ans);
        f(root->right, maxTill, ans);
    }
    int goodNodes(TreeNode* root) {
        int ans = 1;

        int maxTill = root->val;

        f(root->left, maxTill, ans);
        f(root->right, maxTill, ans);
        return ans;
    }
};
