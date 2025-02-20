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
//本题用时过于久！用时26分钟
class Solution {
private:
    int num = 0;
    // //返回的是当前子树和
    // int dfs(TreeNode* cur, int &num)
    // {
    //     if (!cur) return 0;

    //     int rightSum = dfs(cur->right, num);
    //     num += cur->val;
    //     cur->node = num;
    //     int leftSum = dfs(cur->left, num);
    //     return leftSum + rightSum + cur->val;
    // }
public:
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return 0;
        convertBST(root->right);
        root->val = num = num + root->val;
        convertBST(root->left);
        return root;
    }
};