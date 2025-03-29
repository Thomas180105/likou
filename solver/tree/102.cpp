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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return {};

        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            vector<int> level;
            for (int i = 1, qSize = que.size(); i <= qSize; ++i)
            {
                TreeNode* curNode = que.front();
                que.pop();

                level.push_back(curNode->val);

                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }
            res.push_back(level);
        }

        return res;
    }
};