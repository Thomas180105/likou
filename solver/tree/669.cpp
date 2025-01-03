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
    TreeNode *dfs(TreeNode *root, int low, int high)
    {
        if (!root) return nullptr;
        if (root->val > high) return dfs(root->left, low, high);
        if (root->val < low) return dfs(root->right, low, high);

        root->left = dfs(root->left, low, high);
        root->right = dfs(root->right, low, high);
        return root;
    }
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return dfs(root, low, high);
    }
};