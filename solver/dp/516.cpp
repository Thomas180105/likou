class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j]，然后想办法O（1）转移的话就OK
        int sLen = s.size();
        vector<vector<int>> dp(sLen, vector<int>(sLen, 0));
        for (int i = 0; i < sLen; ++i) dp[i][i] = 1;
        for (int i = 0; i < sLen - 1; ++i) dp[i][i + 1] = s[i] == s[i + 1] ? 2 : 1;

        // cout<<"len = 2\n";
        // for (int i = 0; i < sLen - 1; ++i) cout<<"dp["<<i<<"]["<<i + 1<<"] = "<<dp[i][i + 1]<<' ';
        // cout<<'\n';

        for (int len = 3; len <= sLen; ++len)
        {
            // cout<<"len = "<<len<<'\n';
            for (int st = 0; st + len - 1 < sLen; ++st)
            {
                int ed = st + len - 1;
                if (s[st] == s[ed]) dp[st][ed] = 2 + dp[st + 1][ed - 1];
                else dp[st][ed] = max(dp[st][ed - 1], dp[st + 1][ed]);
                // cout<<"dp["<<st<<"]["<<ed<<"] = "<<dp[st][ed]<<' ';
            }
            // cout<<'\n';
        }


        return dp[0][sLen - 1];
    }
};