/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// private:
//     unordered_map<TreeNode*, int> depth;
//     unordered_map<TreeNode*, TreeNode*> fa;
//     void dfs(TreeNode* root, TreeNode* parent, int dep)
//     {
//         fa[root] = parent;
//         depth[root] = dep;
//         if (root->left) dfs(root->left, root, dep + 1);
//         if (root->right) dfs(root->right, root, dep + 1);
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         //DFS()求深度，fa[][0]数组
//         dfs(root, nullptr, 1);
//         if (depth[p] < depth[q]) swap(p, q); //保证p更加远离根节点，后续让p往上爬
//         for (int i = 1, time = depth[p] - depth[q]; i <= time; ++i) p = fa[p];
//         if (p == q) return p;
//         while(p != q) {p = fa[p]; q = fa[q];}
//         return p;
//     }
// };

class Solution {
private:
    //当前子树中是否包含p或者q
    bool dfs(TreeNode* rt, TreeNode* p, TreeNode* q, TreeNode*& ans)
    {
        if (!rt) return false;
        bool left = dfs(rt->left, p, q, ans);
        bool right = dfs(rt->right, p, q, ans);
        if ((left && right) || ((rt == p || rt == q) && (left || right)))
        {
            cout<<"haha\n";
            ans = rt; return true;
        }
        return left || right || rt == p || rt == q;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        dfs(root, p, q, ans);
        return ans;
    }
};