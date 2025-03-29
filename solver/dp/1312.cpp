class Solution {
public:
    int minInsertions(string s) {
        //看起来是dp
        int sLen = s.size();
        vector<vector<int>> dp(sLen + 1, vector<int>(sLen + 1, 1e5));//1-based 闭区间
        for (int i = 1; i <= sLen; ++i) dp[i][i] = 0;
        for (int i = 1; i < sLen; ++i) dp[i][i + 1] = s[i - 1] == s[i] ? 0 : 1;
        for (int len = 3; len <= sLen; ++len)
        {
            for (int l = 1; l + len - 1 <= sLen; ++l)
            {
                int r = l + len - 1;
                dp[l][r] = min(1 + min(dp[l + 1][r], dp[l][r - 1]), dp[l + 1][r - 1] + (s[l - 1] == s[r - 1] ? 0 : 2));
            }
        }
        return dp[1][sLen];
    }
};