class Solution {
public:
    string smallestSubsequence(string s) {
        //想了二十分钟不会做，看的题解
        //这题首先是贪心，然后需要注意到到这里应该使用栈作为数据结构，那么做法就呼之欲出：单调栈维护一个字符单增的栈
        //限制：pop的时候被丢元素后续还有，push的时候待添加的元素还没在栈中

        int sLen = s.size();
        vector<int> cnt(26, 0);
        vector<bool> in(26, false);
        for (int i = 0; i < sLen; ++i) ++cnt[s[i] - 'a'];

        stack<char> stk;
        for (int i = 0; i < sLen; ++i)
        {
            --cnt[s[i] - 'a'];
            if (!in[s[i] - 'a'])//要入栈得有额外条件
            {
                while(!stk.empty() && stk.top() > s[i] && cnt[stk.top() - 'a'] > 0)//要出栈也要有额外条件
                {
                    in[stk.top() - 'a'] = false;
                    stk.pop();
                }
                stk.push(s[i]);
                in[s[i] - 'a'] = true;
            }
        }

        string res;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};