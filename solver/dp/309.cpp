class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        //dp[][0]:手里有股票 dp[][1]:没股票且冷冻 dp[][2]：没股票且自由
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][2] - prices[i], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};