class Solution {
public:
    bool isScramble(string s1, string s2) {
        //考虑是一个二维区间dp，给定一个数组，其是{0, ..., sLen - 1}的排列，求是否可以把它变换为[0, 1, ..., sLen - 1]
        //突然发现这样有一个很大的问题，就是t中可能会出现重复的数字，这个时候似乎不能直接把s中的字符映射到其在t中出现的下标
        //那就考虑三维dp，直接在s1和s2上来做
        int sLen = s1.size();
        vector<vector<vector<bool>>> dp(sLen, vector<vector<bool>>(sLen, vector<bool>(sLen + 1, false)));
        for (int sz = 1; sz <= sLen; ++sz)
        {
            for (int pos1 = 0; pos1 <= sLen - sz; ++pos1)
            {
                for (int pos2 = 0; pos2 <= sLen - sz; ++pos2)
                {
                    if (sz == 1) dp[pos1][pos2][sz] = (s1[pos1] == s2[pos2]);
                    else
                    {
                        for (int sub = 1; sub < sz; ++sub)
                        {
                            if (dp[pos1][pos2][sub] && dp[pos1 + sub][pos2 + sub][sz - sub]) {dp[pos1][pos2][sz] = true; break;}
                            if (dp[pos1][pos2 + sz - sub][sub] && dp[pos1 + sub][pos2][sz - sub]) {dp[pos1][pos2][sz] = true; break;}
                        }
                    }
                }
            }
        }
        return dp[0][0][sLen];
    }
};