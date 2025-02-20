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
    TreeNode* dfs(vector<int>& preorder, vector<int>& postorder, vector<int> &num2postIndex, int pre_l, int pre_r, int post_l, int post_r)
    {
        if (pre_l >= pre_r)
        {
            if (pre_l == pre_r) return new TreeNode(preorder[pre_l]);
            return nullptr;
        }

        int leftCnt = num2postIndex[preorder[pre_l + 1]] - post_l + 1;
        return new TreeNode(
                preorder[pre_l],
                dfs(preorder, postorder, num2postIndex, pre_l + 1, pre_l + leftCnt, post_l, post_l + leftCnt - 1),
                dfs(preorder, postorder, num2postIndex, pre_l + leftCnt + 1, pre_r, post_l + leftCnt, post_r - 1)
        );
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        //preorder 中左右
        //postorder 左右中
        int len = preorder.size();
        vector<int> num2postIndex(len + 1);
        for (int i = 0; i < len; ++i) num2postIndex[postorder[i]] = i;
        return dfs(preorder, postorder, num2postIndex, 0, len - 1, 0, len - 1);
    }
};
