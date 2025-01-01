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
    int helper(TreeNode *cur, int &ans)
    {
        //返回当前子树的高度，并根据经过cur的最长路径去更新最终答案
        if (!cur) {return 0;}
        int l = helper(cur->left, ans);
        int r = helper(cur->right, ans);
        ans = max(ans, l + r);
        return 1 + max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};