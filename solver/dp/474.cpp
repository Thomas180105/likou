class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //def dp[i][j][index]:全部为1-based，其中index的逻辑是使用0~index-1的str,i 0 j 1
        int l = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int zeros, ones;

        for (int k = 1; k <= l; ++k)
        {
            int len = strs[k - 1].size();
            zeros = ones = 0;
            for (int tmpIdx = 0; tmpIdx < len; ++tmpIdx) if (strs[k - 1][tmpIdx] == '0') ++zeros; else ++ones;
            for (int i = m; i >= zeros; --i)
            {
                for (int j = n; j >= ones; --j) dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
            }
        }

        return dp[m][n];
    }
};