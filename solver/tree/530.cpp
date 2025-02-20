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
    int getMinimumDifference(TreeNode* root) {
        stack<pair<TreeNode*, bool>> stk;//true代表可以新鲜出炉了
        stk.push({root, false});
        int pre = -1, ans = 0x7fffffff;
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
                if (pre == -1) pre = curNode->val;
                else {ans = min(ans, curNode->val - pre); pre = curNode->val;}
            }
        }
        return ans;
    }
};