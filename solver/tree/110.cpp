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
private:
    int getDepth(TreeNode *cur)
    {
        //如果不平衡，返回-1，如果平衡，返回高度
        if (!cur) return 0;
        int depL = getDepth(cur->left);
        int depR = getDepth(cur->right);
        if (depL == -1 || depR == -1) return -1;
        if (abs(depL - depR) <= 1) return max(depL, depR) + 1;
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        return (getDepth(root) != -1);
    }
};