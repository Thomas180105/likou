// class Solution {
// public:
//     int integerBreak(int n) {
//         vector<int> dp(n + 1);
//         dp[1] = 1, dp[2] = 1;
//         for (int i = 3; i <= n; ++i)
//         {
//             dp[i] = (i / 2) * (i - i / 2);
//             for (int j = 1; j < i; ++j) dp[i] = max(dp[i], j * dp[i - j]);
//         }
//         return dp[n];
//     }
// };
class Solution {
private:
    int pow(int a, int b) // calculate a^b
    {
        long long ans = 1, base = a;
        while(b)
        {
            if (b & 1) ans *= base;
            base *= base;
            b >>= 1;
        }
        return ans;
    }
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        if (n % 3 == 1) return 4 * pow(3, (n - 4) / 3);
        if (n % 3 == 2) return 2 * pow(3, (n - 2) / 3);
        return pow(3, n / 3);
    }
};