class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2)));
        for (int j = 0; j <= k; ++j)
        {
            dp[0][j][0] = -prices[0];
            dp[0][j][1] = 0;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] - prices[i]);
                if (j) dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] + prices[i]);
                else dp[i][j][1] = dp[i - 1][j][1];
            }
        }
        return dp[n - 1][k][1];
    }
};