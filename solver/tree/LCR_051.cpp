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
    int dfs(TreeNode* root, int &ans)
    {
        if (!root) return 0;
        //统计包含当前root，且左右两子树最多选取其中一个的和,并作为返回值（可以都不选）
        int lRes = dfs(root->left, ans);
        int rRes = dfs(root->right, ans);
        ans = max(ans, root->val + max(0, lRes) + max(0, rRes));
        return root->val + max(0, max(lRes, rRes));
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = -1e5;//注意不能是0
        dfs(root, ans);
        return ans;
    }
};