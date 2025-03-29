class Solution {
public:
    bool checkPartitioning(string s) {
        //二维dp做预处理
        int sLen = s.size();
        vector<vector<bool>> valid(sLen, vector<bool>(sLen));
        for (int i = 0; i < sLen; ++i) valid[i][i] = true;
        for (int i = 0; i < sLen - 1; ++i) valid[i][i + 1] = s[i] == s[i + 1];
        for (int sz = 3; sz <= sLen; ++sz)
        {
            for (int st = 0; st <= sLen - sz; ++st)
            {
                int ed = st + sz - 1;
                valid[st][ed] = valid[st + 1][ed - 1] && (s[st] == s[ed]);
            }
        }

        vector<vector<bool>> dp(sLen + 1, vector<bool>(4, false));//dp[i][j]:前i个字符是否可以被划分为j个回文串,此处i是1-based的
        dp[0][0] = true;
        for (int i = 1; i <= sLen; ++i)
        {
            for (int time = 1; time <= 3; ++time)
            {
                //dp[i][time] 从 dp[pos - 1][time - 1]转移而来，其中pos <= i且valid[pos - 1][i - 1]
                for (int pos = 1; pos <= i; ++pos)
                {
                    if (valid[pos - 1][i - 1] && dp[pos - 1][time - 1]) {dp[i][time] = true; break;}
                }
            }
        }
        return dp[sLen][3];
    }
};