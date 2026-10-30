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
    bool helperRes = false;

    bool helper(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;

        if (root && subRoot) return (root->val == subRoot->val) && helper(root->left, subRoot->left) && helper(root->right, subRoot->right);

        return false;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return false;
        if (!root) return false;

        if (root->val == subRoot->val) helperRes = helper(root, subRoot);

        if (helperRes == false) {
            bool left = isSubtree(root->left, subRoot);
            if (left == false) return isSubtree(root->right, subRoot);
        }

        return helperRes;
    }
};
