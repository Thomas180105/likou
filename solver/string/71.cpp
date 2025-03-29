class Solution {
public:
    string simplifyPath(string path) {
        //想法是先扫描一遍用栈存起来，然后通过栈中数据返回正确答案
        vector<string> stk;
        int pos = 0, sLen = path.size();
        while(pos < sLen)
        {
            if (path[pos] == '/') ++pos;
            else if (path[pos] == '.')
            {
                //先数数一共有多少.
                //允许..abc之类文件名出现，这里需要进一步处理
                int cnt = 0;
                while(pos < sLen && path[pos] == '.') {++cnt; ++pos;}
                // cout<<"the cnt = "<<cnt<<'\n';
                // cout<<"curChar is "<<path[pos]<<'\n';
                if (pos == sLen || path[pos] == '/')//是单纯的点构成的
                {
                    if (cnt == 2)
                    {
                        if (!stk.empty()) stk.pop_back();
                    }
                    else if (cnt >= 3)
                    {
                        stk.push_back(string(cnt, '.'));
                    }
                }
                else//类似于..abc
                {
                    string str(cnt, '.');
                    while(pos < sLen && path[pos] != '/') str += path[pos++];
                    stk.push_back(str);
                }
            }
            else
            {
                string str;
                while(pos < sLen && path[pos] != '/') str += path[pos++];
                stk.push_back(str);
            }
        }

        string res;
        for (auto str : stk)
        {
            // cout<<str<<'\n';
            res += ('/' + str);
        }
        return res.empty() ? "/" : res;
    }
};