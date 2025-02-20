class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int p_cnt = primes.size();
        vector<long long> dp(n + 1, 0x7fffffff);
        dp[1] = 1;
        vector<int> pos(p_cnt, 1);

        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < p_cnt; ++j) dp[i] = min(dp[i], dp[pos[j]] * primes[j]);
            for (int j = 0; j < p_cnt; ++j) if (dp[i] == dp[pos[j]] * primes[j]) ++pos[j];
        }
        return dp[n];
    }
};