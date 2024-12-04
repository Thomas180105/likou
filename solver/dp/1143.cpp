class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j] : 1-based情形，仅用text1前i位，text2前j位
        int m = text1.size(), n = text2.size();
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // for (int i = 1; i <= m; ++i)
        // {
        //     for (int j = 1; j <= n; ++j)
        //     {
        //         if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];//反证法可以证明这样的转移是正确的
        //         else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        //     }
        // }
        // return dp[m][n];
        vector<int> pre(n + 1, 0);
        vector<int> cur(n + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            swap(pre, cur);
            cur[0] = 0;
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1]) cur[j] = 1 + pre[j - 1];
                else cur[j] = max(pre[j], cur[j - 1]);
            }
        }
        return cur[n];
    }
};