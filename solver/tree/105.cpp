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
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &query, int preorder_l, int preorder_r, int inorder_l, int inorder_r)
    {
        if (preorder_l > preorder_r) return nullptr;

        if (preorder_l == preorder_r)
        {
            cout<<"the leaf value is"<<preorder[preorder_l]<<'\n';
            TreeNode *res = new TreeNode(preorder[preorder_l]);
            return res;
        }

        int root_val = preorder[preorder_l];
        int root_index_inorder = query[root_val];
        int l_len = root_index_inorder - inorder_l;

        TreeNode *res = new TreeNode(root_val);
        res->left = dfs(preorder, inorder, query, preorder_l + 1, preorder_l + l_len, inorder_l, root_index_inorder - 1);
        res->right = dfs(preorder, inorder, query, preorder_l + l_len + 1, preorder_r, root_index_inorder + 1, inorder_r);

        return res;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> query;
        int preSize = preorder.size(), inSize = inorder.size();
        for (int i = 0; i < inSize; ++i) query[inorder[i]] = i;

        return dfs(preorder, inorder, query, 0, preSize - 1, 0, inSize - 1);
    }
};