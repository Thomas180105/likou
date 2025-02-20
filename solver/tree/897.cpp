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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* pre = nullptr;
        TreeNode* res;
        stack<pair<TreeNode*, bool>> stk;//true:已经准备就绪
        stk.push({root, false});
        while(!stk.empty())
        {
            auto [curNode, flag] = stk.top();
            stk.pop();
            if (!flag)
            {
                if (curNode->right) stk.push({curNode->right, false});
                stk.push({curNode, true});
                if (curNode->left) stk.push({curNode->left, false});
            }
            else
            {
                curNode->left = nullptr;
                if (pre == nullptr) {res = pre = curNode; curNode->left = nullptr;}
                else {pre->right = curNode; curNode->left = nullptr; pre = curNode;}
            }
        }
        return res;
    }
};