//用时：05:21
class Solution {
private:
    void dfs(int n, int l, int r, string &str, vector<string> &res)
    {
        if (l == n && r == n) {res.push_back(str); return;}
        if (l < n) {str += '('; dfs(n, l + 1, r, str, res); str.pop_back();}
        if (r < l) {str += ')'; dfs(n, l, r + 1, str, res); str.pop_back();}
    }
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return {};
        vector<string> res;
        string str;
        dfs(n, 0, 0, str, res);
        return res;
    }
};