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
    const int MAX = 0x7fffffff;
    const int MIN = -MAX - 1;
    bool dfs(TreeNode *root, int &minVal, int &maxVal)
    {
        if (!root) return true;
        int leftMin = MAX, leftMax = MIN, rightMin = MAX, rightMax = MIN;
        //这里可以使用条件短路，如果false了就没有必要维护minVl和maxVal了
        if (!dfs(root->left, leftMin, leftMax) || !dfs(root->right, rightMin, rightMax)) return false;
        minVal = min(root->val, leftMin), maxVal = max(root->val, rightMax);

        return ((!root->left || root->val > leftMax) && (!root->right || root->val < rightMin));//这里要特判，否则可能root->val刚好等于MAX或MIN时会出现问题
    }
public:
    bool isValidBST(TreeNode* root) {
        // if (!root) return true;
        // if ((root->left && root->left->val >= root->val) || (root->right && root->right->val <= root->val)) return false;
        // return isValidBST(root->left) && isValidBST(root->right);
        //上述代码错误，因为只将root和儿子比较而不是和儿子子树中所有树比较
        int minVal = MAX, maxVal = MIN;
        return dfs(root, minVal, maxVal);
    }
};