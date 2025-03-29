class Solution {
private:
    const long long mod = 1e9 + 7;
public:
    int countHousePlacements(int n) {
        //由于两边是独立的，所以只需要计算一边的可能，然后平方即可；对于一边的情况，先试试dp
        long long ans = 0;
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        //dp[i][0]:i处不放房子，0~i处合法的放置方法总数
        //dp[i][1]:i处放房子，0~i处合法的放置方法总数

        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = dp[i - 1][0];
        }

        ans = (dp[n - 1][0] + dp[n - 1][1]) % mod;
        ans = (ans * ans) % mod;
        return static_cast<int>(ans);
    }
};