class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        vector<vector<int>> dp(len + 1, vector<int>(2));//dp[i][0]:未持有股票，第i天（1-based）；dp[i][1]：持有股票，第i天

        dp[0][0] = 0, dp[0][1] = -1e5;

        for (int i = 1; i <= len; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
        }

        return dp[len][0];
    }
};