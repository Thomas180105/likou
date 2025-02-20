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
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};

        vector<int> res;

        stack<pair<TreeNode*, int>> stk;//0:第一次见 1：第二次见
        stk.push({root, 0});

        while(!stk.empty())
        {
            auto [cur, color] = stk.top();
            stk.pop();

            if (color == 0)
            {
                stk.push({cur, 1});
                if (cur->right) stk.push({cur->right, 0});
                if (cur->left) stk.push({cur->left, 0});
            }
            else if (color == 1) stk.push({cur, 2});
            else res.push_back(cur->val);
        }

        return res;
    }
};