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
    bool balanced = true;
    int helper(TreeNode* root) {
        if (root == nullptr) return 0;
        int lDepth, rDepth;

        lDepth = helper(root->left);
        rDepth = helper(root->right);

        if (lDepth - rDepth > 1 || lDepth - rDepth < -1) balanced = false;

        return 1 + max(lDepth, rDepth);  
    }

    bool isBalanced(TreeNode* root) {
        helper(root);
        return balanced;
    }
};
