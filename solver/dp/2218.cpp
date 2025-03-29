class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        //考虑dp[i][j]：前i个piles,一共j次机会，能够得到的最大收入，i为1-based
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                int sum = 0;
                dp[i][j] = dp[i - 1][j];
                for (int t = 0, bound = min((int)piles[i - 1].size(), j); t < bound; ++t)
                {
                    sum += piles[i - 1][t];
                    dp[i][j] = max(sum + dp[i - 1][j - t - 1], dp[i][j]);
                }
            }
        }
        return dp[n][k];
    }
};