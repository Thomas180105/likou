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
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inMap, int in_l, int in_r, int post_l, int post_r)
    {
        // cout<<"("<<in_l<<", "<<in_r<<") ("<<post_l<<", "<<post_r<<")\n";
        if (in_l >= in_r)
        {
            if (in_l == in_r) return new TreeNode(inorder[in_l]);
            return nullptr;
        }
        int leftCnt = inMap[postorder[post_r]] - in_l;
        return new TreeNode(
                postorder[post_r],
                dfs(inorder, postorder, inMap, in_l, in_l + leftCnt - 1, post_l, post_l + leftCnt - 1),
                dfs(inorder, postorder, inMap, in_l + leftCnt + 1, in_r, post_l + leftCnt, post_r - 1)
        );
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //inorder 左中右 postoredr 左右中
        int len = postorder.size();
        unordered_map<int, int> inMap;
        for (int i = 0; i < len; ++i) inMap[inorder[i]] = i;
        return dfs(inorder, postorder, inMap, 0, len - 1, 0, len - 1);
    }
};