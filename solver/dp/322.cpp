class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = coins.size();
        //dp[index][sum]:1-based 完全背包问题
        vector<int> dp(amount + 1, 1e5);
        dp[0] = 0;
        // for (int i = 1; i <= m; ++i)
        // {
        //     int tmp = coins[i - 1];
        //     for (int j = amount; j >= tmp; --j) dp[j] = min(dp[j], 1 + dp[j - tmp]);
        // }

        for (int j = 1; j <= amount; ++j)
        {
            for (int i = 1; i <= m; ++i)
            {
                int tmp = coins[i - 1];
                if (j >= tmp) dp[j] = min(dp[j], 1 + dp[j - tmp]);
            }
        }
        return (dp[amount] == 1e5) ? -1 : dp[amount];
    }
};