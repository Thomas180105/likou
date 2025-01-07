//用时: 05:53
class Solution {
private:
    void dfs(int n, int l_in, int r_in, vector<string> &res, string str)
    {
        if (l_in == n && r_in == n) {res.push_back(str); return;}

        if (l_in < n) dfs(n, l_in + 1, r_in, res, str + '(');//放入(
        if (l_in > r_in) dfs(n, l_in, r_in + 1, res, str + ')');
    }
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return {};
        vector<string> res;
        dfs(n, 0, 0, res, "");
        return res;
    }
};