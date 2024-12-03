class Solution {
public:
    // static const int N = 50;
    // int dp[N];
    int climbStairs(int n) {
        // dp[0] = dp[1] = 1;
        // for (int i = 2; i <= n; ++i) dp[i] = dp[i - 1] + dp[i - 2];
        // return dp[n];
        if (n <= 2) return n;
        int pre1 = 1, pre2 = 2, cur;
        for (int i = 3; i <= n; ++i)
        {
            cur = pre1 + pre2;
            pre1 = pre2;
            pre2 = cur;
        }
        return cur;
    }
};