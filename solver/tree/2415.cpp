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
    TreeNode* reverseOddLevels(TreeNode* root) {
        //没想到好用的方法，先蠢方法走一波
        if (!root) return root;
        vector<vector<int>> history;
        queue<TreeNode*> que;

        que.push(root);
        int curLevel = 0;
        while(!que.empty())
        {
            vector<int> levelVec;
            for (int i = 0, qSize = que.size(); i < qSize; ++i)
            {
                auto curNode = que.front();
                que.pop();

                if (curLevel % 2 == 1) levelVec.push_back(curNode->val);

                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }
            if (curLevel % 2 == 1) history.push_back(levelVec);
            ++curLevel;
        }

        que.push(root);
        curLevel = 0;
        while(!que.empty())
        {
            for (int i = 0, qSize = que.size(); i < qSize; ++i)
            {
                auto curNode = que.front();
                que.pop();

                if (curLevel % 2 == 1) curNode->val = history[(curLevel - 1) / 2][history[(curLevel - 1) / 2].size() - 1 - i];

                if (curNode->left) que.push(curNode->left);
                if (curNode->right) que.push(curNode->right);
            }
            ++curLevel;
        }

        return root;
    }
};