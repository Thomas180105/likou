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
    void dfs(string & cur, TreeNode* node, vector<string> &res)
    {
        //确保此处node不是空节点，并且cur中已经有了node的信息
        if (!node->left && !node->right)
        {
            res.push_back(cur);
            return;
        }

        if (node->left)
        {
            string copy = cur;
            cur += "->";
            cur += to_string(node->left->val);
            dfs(cur, node->left, res);
            cur = copy;
        }

        if (node->right)
        {
            string copy = cur;
            cur += "->";
            cur += to_string(node->right->val);
            dfs(cur, node->right, res);
            cur = copy;
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        string str = to_string(root->val);
        dfs(str, root, res);
        return res;
    }
};

//注：来自题解的更加清爽的写法：
//class Solution {
//public:
//    void construct_paths(TreeNode* root, string path, vector<string>& paths) {
//        if (root != nullptr) {
//            path += to_string(root->val);
//            if (root->left == nullptr && root->right == nullptr) {  // 当前节点是叶子节点
//                paths.push_back(path);                              // 把路径加入到答案中
//            } else {
//                path += "->";  // 当前节点不是叶子节点，继续递归遍历
//                construct_paths(root->left, path, paths);
//                construct_paths(root->right, path, paths);
//            }
//        }
//    }
//
//    vector<string> binaryTreePaths(TreeNode* root) {
//        vector<string> paths;
//        construct_paths(root, "", paths);
//        return paths;
//    }
//};