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
    int widthOfBinaryTree(TreeNode* root) {
        //层次遍历的同时打编号即可（左儿子2x,右儿子2x+1）
        //但是下面这个方案会导致溢出，只能处理很浅的树，long long存num一样溢出
        queue<pair<TreeNode*, unsigned long long>> que;
        que.push({root, 1});
        unsigned long long ans = 0;
        while(!que.empty())
        {
            int curSz = que.size();
            unsigned long long L, R;
            for (int i = 0; i < curSz; ++i)
            {
                auto [node, num] = que.front();
                que.pop();

                if (i == 0) L = num;
                if (i == curSz - 1) R = num;

                if (node->left) que.push({node->left, 2 * num});
                if (node->right) que.push({node->right, 2 * num + 1});
            }
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};