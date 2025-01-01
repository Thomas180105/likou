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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode *> que;
        que.push(root);

        int level = 1, next_level = 0;

        while(!que.empty())
        {
            vector<int> vec;
            for (int i = 0; i < level; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();

                if (!cur) vec.push_back(-200);
                else
                {
                    vec.push_back(cur->val);
                    que.push(cur->left);
                    que.push(cur->right);
                    next_level += 2;
                }
            }

            for (int i = 0; i < level / 2; ++i) if (vec[i] != vec[level - 1 - i]) return false;
            level = next_level;
            next_level = 0;
        }

        return true;
    }
};