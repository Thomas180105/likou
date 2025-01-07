- 如果要生成的东西比较占用内存，此处我们应该用引用传递，而不是值传递。这样可以减少内存的占用。
对应的，程序实现上，就应该回溯，如下
```cpp
class Solution {
private:
    void dfs(int n, int l_in, int r_in, vector<string> &res, string &str)
    {
        if (l_in == n && r_in == n) {res.push_back(str); return;}  

        if (l_in < n) 
        {
            str += '(';
            dfs(n, l_in + 1, r_in, res, str);
            str = str.substr(0, str.size() - 1);
        }
        if (l_in > r_in) 
        {
            str += ')';
            dfs(n, l_in, r_in + 1, res, str);
            str = str.substr(0, str.size() - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return {};
        vector<string> res;
        string tmpStr;
        dfs(n, 0, 0, res, tmpStr);
        return res;
    }
};
```

- 注：可以直接str.pop_back()，不用substr