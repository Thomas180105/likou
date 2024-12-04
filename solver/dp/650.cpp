class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = i;
            // for (int j = 2; j <= i / 2; ++j) if (i % j == 0) dp[i] = min(dp[i], dp[j] + dp[i / j]);
            int tmp = sqrt(i);
            for (int j = tmp; j >= 2; --j) if (i % j == 0) {dp[i] = min(dp[i], dp[j] + dp[i / j]); break;} //这个不会证明为什么，先用上面注释地保险一些
        }
        return dp[n];
    }
};