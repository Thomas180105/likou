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
    unordered_map<long long, int> prefix;
    int dfs(TreeNode* root, long long preSum, int targetSum)
    {
        //返回的是以当前节点为结尾的序列的个数
        if (!root) return 0;

        int res = 0;
        preSum += root->val;
        if (prefix.count(preSum - targetSum)) res += prefix[preSum - targetSum];
        ++prefix[preSum];
        res += dfs(root->left, preSum, targetSum);
        res += dfs(root->right, preSum, targetSum);
        --prefix[preSum];

        return res;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};