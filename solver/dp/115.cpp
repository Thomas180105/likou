class Solution {
public:
    int numDistinct(string s, string t) {
        //直觉上是dp,为了简化初始化均使用1-based
        int sLen = s.size(), tLen = t.size(), mod = 1e9 + 7;
        vector<int> dp(tLen + 1, 0);//dp[i][j]:s.substr(0, i)的子序列中t.substr(0, j)出现的次数
        //dp[0][0] = 1;最先写的初始化的时候大意了没有闪,应该是dp[i][0] = 1;
        dp[0] = 1;
        for (int i = 1; i <= sLen; ++i)
        {
            for (int j = tLen; j >= 1; --j)
            {
                if (s[i - 1] != t[j - 1]) dp[j] = dp[j];
                else dp[j] = (dp[j - 1] + dp[j]) % mod;
            }
        }
        return dp[tLen];
    }
};