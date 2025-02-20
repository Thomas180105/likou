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
    int findBottomLeftValue(TreeNode* root) {
        int val;
        queue<TreeNode*> que;
        que.push(root);
        int sz = 1, tmp;
        while(!que.empty())
        {
            val = que.front()->val;
            tmp = 0;
            for (int i = 0; i < sz; ++i)
            {
                auto curNode = que.front();
                que.pop();
                if (curNode->left) {que.push(curNode->left); ++tmp;}
                if (curNode->right) {que.push(curNode->right); ++tmp;}
            }
            sz = tmp;
        }
        return val;
    }
};