class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;//dp[0][1~]为false
        bool flag = false;
        for (int index = 0; index < n; ++index)
        {
            if (p[index] != '*')
            {
                if (flag) break;
                else flag = true;
            }
            else {flag = false; dp[0][index + 1] = true;}
        }

        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                char cur = p[j - 1];
                if (cur != '.' && cur != '*') dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == cur);
                else if (cur == '.') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 2] != '.' && s[i - 1] != p[j - 2]) dp[i][j] = dp[i][j - 2];//此时cur为'*'，根据题目中的限制，前面一定有字符，且前面不是'*'
                else dp[i][j] = dp[i - 1][j] || dp[i][j - 2] || dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};