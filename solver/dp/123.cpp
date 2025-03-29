class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp0: 0次，目前手里有票； dp1： 1次，目前手里没票； dp2： 1次，目前手里有票； dp3:2次
        vector<int> dp(4);
        dp[0] = dp[2] = -2e5;
        for (int i = 0, len = prices.size(); i < len; ++i)
        {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
            dp[2] = max(dp[2], dp[1] - prices[i]);
            dp[3] = max(dp[3], dp[2] + prices[i]);
        }
        return max(dp[1], dp[3]);
    }
};