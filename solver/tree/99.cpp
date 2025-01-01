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
    void recoverTree(TreeNode* root) {
        stack<pair<TreeNode *, int>> stk;
        stk.push({root, 0});

        TreeNode *node1 = nullptr;
        TreeNode *node2 = nullptr;
        TreeNode *prev = nullptr;
        while(!stk.empty())
        {
            auto [cur, color] = stk.top();
            stk.pop();

            if (color == 1)
            {
                if (prev && prev->val > cur->val)
                {
                    if (node1) {swap(node1->val, cur->val); return;}
                    else {node1 = prev; node2 = cur;}
                }
                prev = cur;
            }
            else if (color == 0)
            {
                if (cur->right) stk.push({cur->right, 0});
                stk.push({cur, 1});
                if (cur->left) stk.push({cur->left, 0});
            }
        }

        swap(node1->val, node2->val);
    }
};