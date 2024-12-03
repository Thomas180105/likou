class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int worcCnt = wordDict.size();
        int strLen = s.size();

        vector<bool> dp(strLen + 1, false);
        dp[0] = true;

        for (int i = 1; i <= strLen; ++i)
        {
            //solve dp[i]
            for (int j = 0; j < worcCnt; ++j)
            {
                //i , j 
                int k = wordDict[j].size();
                if (i - k < 0) continue;
                bool match_flag = true;
                for (int index = 0; index < k; ++index)
                {
                    if (wordDict[j][index] != s[i - k + index]) {match_flag = false; break;}
                }
                if (match_flag && dp[i - k]) {dp[i] = true; break;}
            }
        }
        return dp[strLen];
    }
};