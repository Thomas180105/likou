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
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> que;
        if (!root) return 0;
        que.push(root);
        int level_cnt = 1, next_level, depth = 0;

        while(!que.empty())
        {
            for (int i = 1; i <= level_cnt; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                // cout<<"now the depth is" <<depth<<" and the cur node is "<<cur->val<<'\n';
                if (cur->left) {que.push(cur->left); ++next_level;}
                if (cur->right) {que.push(cur->right); ++next_level;}
            }
            ++depth;
            level_cnt = next_level;
            next_level = 0;
        }

        return depth;
    }
};