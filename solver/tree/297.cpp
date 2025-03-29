/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//以下是第一次遇到这题写的迭代的代码，35minAC，如果第二次刷到的话写一个递归版本的
class Codec {
private:
    int str2num(const string &str)
    {
        int res = 0;
        for (int i = 1; i <= 4; ++i) res = res * 10 + (str[i] - '0');
        return str[0] == '+' ? res : -res;
    }
    string num2str(int num)
    {
        string res;
        for (int i = 1; i <= 4; ++i)
        {
            res += ('0' + num % 10);
            num /= 10;
        }
        res += ((num >= 0) ? '+' : '-');
        reverse(res.begin(), res.end());
        return res;
    }
public:
    //直接考虑用前序遍历，不过正常来说不足以表示足够多的信息，所以这里遇到空节点的时候就编码为"#####"
    //正数就是+1000到+0000，负数就是-1000到-0001
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        stack<TreeNode*> stk;//(节点，是否是第二次见)
        stk.push(root);

        while(!stk.empty())
        {
            auto cur = stk.top();
            stk.pop();

            res += cur ? num2str(cur->val) : "#####";
            if (cur) {stk.push(cur->right); stk.push(cur->left);}
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* rt = new TreeNode(1e5);//类似于链表题里面的dummyHead
        int len = data.size();
        stack<pair<TreeNode*, bool>> stk;//用一个栈来存当前这个前序遍历路径上的祖先,第二位表征现在是否在找右儿子
        stk.push({rt, false});

        for (int pos = 0; pos < len; pos += 5)
        {
            if (data[pos] == '#')
            {
                auto [cur, state] = stk.top();
                stk.pop();

                if (!state)
                {
                    cur->left = nullptr;
                    stk.push({cur, true});
                }
                else
                {
                    cur->right = nullptr;
                    while(true)
                    {
                        auto [fa, faState] = stk.top();
                        stk.pop();

                        if (!faState) {fa->left = cur; stk.push({fa, true}); break;}
                        else {fa->right = cur; cur = fa;}
                    }
                }

            }
            else
            {
                int val = str2num(data.substr(pos, 5));
                TreeNode* newNode = new TreeNode(val);
                stk.push({newNode, false});
            }
        }

        return rt->left;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));