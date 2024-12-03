class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 1e5);
        dp[0] = 0;
        for (int num = 1; num <= n; ++num)
        {
            for (int i = 1; i * i <= num; ++i) dp[num] = min(dp[num], dp[num - i * i] + 1);
        }
        return dp[n];
    }
};