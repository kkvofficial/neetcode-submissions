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
    int dfs(TreeNode* root, int maxV) {
        if (!root) return 0;
        int num = 0;
        if (root->val >= maxV) {
            num = 1;
            maxV = root->val;
        }

        return num + dfs(root->left, maxV) + dfs(root->right, maxV);
    }

    int goodNodes(TreeNode* root) {
        int res = dfs(root, root->val);
        return res;
    }
};
