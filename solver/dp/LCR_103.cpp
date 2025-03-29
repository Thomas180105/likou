class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //模板题，先写一个二维的形式
        int cLen = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(amount + 1, vector<int>(cLen + 1, amount + 1));//dp[amount][i]:表示用coins[0] ~coins[i - 1]来组成amout，最少需要的硬币数
        for (int j = 0; j <= cLen; ++j) dp[0][j] = 0;
        for (int j = 1; j <= cLen; ++j)
        {
            for (int sum = 0; sum <= amount; ++sum)
            {
                if (sum >= coins[j - 1]) dp[sum][j] = min(dp[sum][j - 1], dp[sum - coins[j - 1]][j] + 1);
                else dp[sum][j] = dp[sum][j - 1];
            }
        }
        return dp[amount][cLen] == amount + 1 ? -1 : dp[amount][cLen];
    }
};