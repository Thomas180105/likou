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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;

        queue<TreeNode *> que;
        que.push(root);

        int level = 1, next_level = 0;
        double sum = 0;
        while(!que.empty())
        {
            for (int i = 0; i < level; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();

                sum += cur->val;
                if (cur->left) {que.push(cur->left); ++next_level;}
                if (cur->right) {que.push(cur->right); ++next_level;}
            }

            res.push_back(sum / level);
            level = next_level;
            next_level = sum = 0;
        }

        return res;
    }
};