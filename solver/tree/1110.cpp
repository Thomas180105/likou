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
    unordered_set<int> hash;
    TreeNode *dfs(TreeNode *cur, vector<TreeNode*> &res, bool is_root)
    {
        if (!cur) return nullptr;
        bool dFlag = hash.count(cur->val);
        if (!dFlag)
        {
            if (is_root) res.push_back(cur);
            cur->left = dfs(cur->left, res, false);
            cur->right = dfs(cur->right, res, false);
            return cur;
        }
        else
        {
            dfs(cur->left, res, true);
            dfs(cur->right, res, true);
            return nullptr;
        }


    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        hash.clear();
        for (int i = 0, l = to_delete.size(); i < l; ++i) hash.insert(to_delete[i]);
        vector<TreeNode*> res;
        dfs(root, res, true);
        return res;
    }
};