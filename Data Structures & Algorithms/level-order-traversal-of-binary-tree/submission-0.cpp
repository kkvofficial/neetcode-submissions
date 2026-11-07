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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> res;

        TreeNode* temp;

        if (!root) return res;
        q.push(root);

        while (!q.empty()) {
            vector<int> tv;
            int q_size = q.size();

            for (int i=0; i<q_size; i++) {
                temp = q.front();
                q.pop();

                tv.push_back(temp->val);

                if (temp->left != nullptr) q.push(temp->left);
                if (temp->right != nullptr) q.push(temp->right);
            }
            res.push_back(tv);
        }
        return res;
    }
};
