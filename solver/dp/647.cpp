class Solution {
public:
    int countSubstrings(string s) {
        int s_len = s.size();
        vector<vector<bool>> dp(s_len, vector<bool>(s_len, false));

        int ans = 0;
        for (int len = 1; len <= s_len; ++len)
        {
            for (int l = 0; l < s_len + 1 - len; ++l)
            {
                int r = l + len - 1;
                if (len == 1) dp[l][r] = true;
                else if (len == 2) dp[l][r] = (s[l] == s[r]);
                else dp[l][r] = (dp[l + 1][r - 1] && (s[l] == s[r]));

                if (dp[l][r]) ++ans;
            }
        }

        return ans;
    }
};