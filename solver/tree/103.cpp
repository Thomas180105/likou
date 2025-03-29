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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        vector<vector<int>> ans;

        que.push(root);
        int level = 1;
        while(!que.empty())
        {
            vector<int> curVec;
            for (int i = 0, qSize = que.size(); i < qSize; ++i)
            {
                auto curNode = que.front();
                que.pop();

                curVec.push_back(curNode->val);

                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }
            if (level % 2 == 0) reverse(curVec.begin(), curVec.end());
            ans.push_back(curVec);
            ++level;
        }
        return ans;
    }
};