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
//这是第一次见到本题之后写的抽象迭代，其中由于有大量对于root的维护容易被忘记，所以当时debug了很久
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         TreeNode* cur = root;
//         TreeNode* pre = nullptr;
//         while(cur)
//         {
//             if (cur->val == key) break;
//             else if (cur->val > key) {pre = cur; cur = cur->left;}
//             else {pre = cur; cur = cur->right;}
//         }
//         if (!cur) return root;

//         if (!cur->left && !cur->right)
//         {
//             if (pre) cur == pre->left ? pre->left = nullptr : pre->right = nullptr;
//             else root = nullptr;
//             delete cur;
//         }
//         else if (cur->left && cur->right)
//         {
//             TreeNode* des = cur->right;
//             TreeNode* desFa = cur;
//             while(des->left) {desFa = des; des = des->left;}
//             swap(cur->val, des->val);

//             if (!des->left && !des->right)
//             {
//                 des == desFa->left ? desFa->left = nullptr : desFa->right = nullptr;
//                 delete des;
//             }
//             else
//             {
//                 TreeNode* son = (des->left ? des->left : des->right);
//                 des == desFa->left ? desFa->left = son : desFa->right = son;
//                 delete des;
//             }
//         }
//         else
//         {
//             TreeNode* son = (cur->left ? cur->left : cur->right);
//             if (pre) cur == pre->left ? pre->left = son : pre->right = son;
//             else root = son;
//             delete cur;
//         }

//         return root;
//     }
// };

// 参考题解写的一个递归，使用了delete防止了内存泄露
// class Solution {
// public:
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if (root == nullptr) return nullptr;
//         if (root->val > key)
//         {
//             root->left = deleteNode(root->left, key);
//             return root;
//         }
//         if (root->val < key)
//         {
//             root->right = deleteNode(root->right, key);
//             return root;
//         }
//         if (root->val == key)
//         {
//             if (!root->left && !root->right) {delete root; return nullptr;}
//             if (!root->right)
//             {
//                 TreeNode* ret = root->left;
//                 delete root;
//                 return ret;
//             }
//             if (!root->left)
//             {
//                 TreeNode* ret = root->right;
//                 delete root;
//                 return ret;
//             }
//             TreeNode *successor = root->right;
//             while (successor->left) successor = successor->left;
//             root->val = successor->val;
//             root->right = deleteNode(root->right, successor->val);
//             return root;
//         }
//         return root;
//     }
// };

// deepseek写的一版迭代，逻辑更加清晰，与原来我自己写的，这一版有如下优势
// 没有将待删节点有两/一/零儿子直接if-else串起来，而是如果有两儿子先归约到一/零儿子的情况，然后再处理。这样可以避免一/零儿子的处理逻辑写多次
// delete和return最大限度地各路径统一，避免每一个if-else下面都写一份
// 真正要删除节点的代码只集中在最后几行，维护root起来更加不容易遗漏
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur = root;
        TreeNode* pre = nullptr;

        while (cur && cur->val != key)
        {
            pre = cur;
            cur = (cur->val > key) ? cur->left : cur->right;
        }
        if (!cur) return root;

        // 如果要删除的节点有两个子节点,将其转化为下一种情况，此时删除还没有发生
        if (cur->left && cur->right)
        {
            TreeNode* des = cur->right;
            TreeNode* desFa = cur;
            while (des->left)
            {
                desFa = des;
                des = des->left;
            }
            cur->val = des->val;
            cur = des;
            pre = desFa;
        }

        // 处理要删除的节点有一个子节点或没有子节点的情况
        TreeNode* child = (cur->left) ? cur->left : cur->right;
        if (!pre) root = child;
        else cur == pre->left ? pre->left = child : pre->right = child;

        delete cur;
        return root;
    }
};