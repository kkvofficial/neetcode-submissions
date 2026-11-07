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
    int level = 0;
    vector<int> res;

    void dfs(TreeNode* root, int d) {
        if (!root) return;

        if (d >= level) {
            res.push_back(root->val);
            level++;
        }

        if (root->right != nullptr) dfs (root->right, d+1);
        if (root->left != nullptr) dfs (root->left, d+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        dfs (root, 0);
        return res;
    }
};
