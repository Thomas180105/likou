class Solution {
public:
    int numDecodings(string s) {
        //dp[i](1-based)：以i下标为结尾的子串有多少解码方式。dp[0] = 1;
        int n = s.size();
        if (n == 1) return (s[0] == '0') ? 0 : 1;
        if (s[0] == '0') return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            if (s[i - 1] == '0')
            {
                if (s[i - 2] == '1' || s[i - 2] == '2') dp[i] = dp[i - 2];
                else return 0;
            }
            else if (s[i - 1] >= '1' && s[i - 1] <= '6')
            {
                if (s[i - 2] == '1' || s[i - 2] == '2') dp[i] = dp[i - 1] + dp[i - 2];
                else dp[i] = dp[i - 1];
            }
            else
            {
                if (s[i - 2] == '1') dp[i] = dp[i - 1] + dp[i - 2];
                else dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};