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
    void dfs(TreeNode *root, int &left, int &right, int &ans)//指当前节点选择走left之后能得到的最大路径节点数
    {
        if (!root) return;

        int lSonLeft = 0, lSonRight = 0, rSonLeft = 0, rSonRight = 0;
        dfs(root->left, lSonLeft, lSonRight, ans);
        dfs(root->right, rSonLeft, rSonRight, ans);
        left = lSonRight + 1;
        right = rSonLeft + 1;
        ans = max(ans, max(left, right) - 1);
    }
public:
    int longestZigZag(TreeNode* root) {
        int l = 0, r = 0, ans = 0;
        dfs(root, l, r, ans);
        return ans;
    }
};