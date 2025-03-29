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
    unordered_map<TreeNode*, int> rtMax;//当前子树中，包含当前根节点,且最多只能与左子树/右子树之一有交集的路径对应的最大值
    void dfs1(TreeNode *root)
    {
        if (!root) return;
        dfs1(root->left);
        dfs1(root->right);
        rtMax[root] = root->val + max(0, max(rtMax[root->left], rtMax[root->right]));
    }
    void dfs2(TreeNode* root, int &res)
    {
        if (!root) return;
        res = max(res, root->val + max(0, rtMax[root->left]) + max(0, rtMax[root->right]));
        dfs2(root->left, res);
        dfs2(root->right, res);
    }
public:
    int maxPathSum(TreeNode* root) {
        //看起来像是树链剖分那一块？但不太记得怎么写了，先偷懒写个递归解法
        rtMax[nullptr] = 0;
        dfs1(root);
        int res = -1e5;
        dfs2(root, res);
        return res;
    }
};