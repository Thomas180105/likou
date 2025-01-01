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
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;

        stack<TreeNode *> que;
        que.push(root);

        while(!que.empty())
        {
            TreeNode *cur = que.top();
            que.pop();

            res.push_back(cur->val);
            if (cur->right) que.push(cur->right);
            if (cur->left) que.push(cur->left);
        }

        return res;
    }
};