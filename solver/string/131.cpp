class Solution {
    void dfs(vector<vector<string>> &res, vector<string> &cur, const vector<vector<int>> &findNext, const string &s, int pos)
    {
        if (pos == s.size()) {res.push_back(cur); return;}

        for (auto newPos : findNext[pos])
        {
            cur.push_back(s.substr(pos, newPos - pos + 1));
            dfs(res, cur, findNext, s, newPos + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int sLen = s.size();
        vector<vector<bool>> dp(sLen, vector<bool>(sLen, false));//0-based 区间dp，表示当前字串是不是回文串
        vector<vector<int>> findNext(sLen);//收集使得dp[i][] = true的j

        for (int i = 0; i < sLen; ++i) dp[i][i] = true;
        for (int i = 0; i < sLen - 1; ++i) dp[i][i + 1] = s[i] == s[i + 1];
        for (int l = 3; l <= sLen; ++l)
        {
            for (int i = 0; i <= sLen - l; ++i) dp[i][i + l - 1] = dp[i + 1][i + l - 2] && s[i] == s[i + l - 1];
        }
        for (int i = 0; i < sLen; ++i)
        {
            for (int j = i; j < sLen; ++j) if (dp[i][j]) findNext[i].push_back(j);
        }

        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, cur, findNext, s, 0);
        return res;
    }
};