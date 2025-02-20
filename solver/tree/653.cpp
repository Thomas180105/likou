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
    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        stack<pair<TreeNode*, bool>> stk;
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
            else vec.push_back(curNode->val);
        }

        int l = 0, r = vec.size() - 1;
        while(l < r)
        {
            if (vec[l] + vec[r] == k) return true;
            else if (vec[l] + vec[r] < k) ++l;
            else --r;
        }
        return false;
    }
};