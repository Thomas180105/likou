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
    const static int N = 1e9;
    struct hst{
        int a, b, c;
    };
    hst dfs(TreeNode* rt)
    {
        if (!rt) return {N, 0, 0};

        hst lson = dfs(rt->left);
        hst rson = dfs(rt->right);
        int la = lson.a, lb = lson.b, lc = lson.c;
        int ra = rson.a, rb = rson.b, rc = rson.c;

        int a = lc + rc + 1;
        int b = min(a, min(la + rb, lb + ra));
        int c = min(a, lb + rb);//这里写成c = lb + rb过不了，想想为什么？
        return {a, b, c};
    }
public:
    int minCameraCover(TreeNode* root) {
        //看起来是就是树上dp递归做
        //想了二十分钟不会做，中午看完题解之后晚上来交一发，一周之后重做

        //递归地考虑问题，我们要覆盖一棵树有两个做法
        //方法一是选取root，然后需要左儿子的左右子树被覆盖、右子树的左右子树被覆盖
        //方法二是不选去root，然后需要左子树被覆盖、右子树被覆盖，同时左右子树至少其中一个的root被选取

        //综上我们可以发现要解决原问题，至少需要树上dp求解下面三个状态
        //a : root被选取，覆盖当前树
        //b : 不论root选取否，覆盖当前树
        //c : 无论root选取否，覆盖当前左子树、右子树

        //记左子树状态是(la, lb, lc)，右子树状态是(ra, rb, rc)， 这样一来一开始两个选取方式就可以写成
        //b = min(a, min(la + rb, lb + ra));
        //而a和c也可以下面这样转移，整个系统自洽
        //a = lc + rc + 1
        //c = lb + rb
        hst res = dfs(root);
        return res.b;
    }
};