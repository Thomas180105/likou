class Solution {
public:
    int findRotateSteps(string ring, string key) {
        //一眼dp，dp[i][pos]表示已经解决key[0]~key[i - 1]，且当前位置在ring第pos（0-based）个字符所需要的步数
        int rLen = ring.size(), kLen = key.size();
        vector<vector<int>> dp(kLen + 1, vector<int>(rLen, 1e5));//可压缩

        //dp[i][pos] = dp[i - 1][prePos] + cost(prePos, pos),其中ring[pos] == key[i - 1]的时候才更新
        dp[0][0] = 0;
        for (int i = 1; i <= kLen; ++i)
        {
            for (int pos = 0; pos < rLen; ++pos)
            {
                if (ring[pos] == key[i - 1])
                {
                    for (int prePos = 0; prePos < rLen; ++prePos)
                    {
                        dp[i][pos] = min(dp[i][pos], dp[i - 1][prePos] + min((prePos - pos + rLen) % rLen, (pos - prePos + rLen) % rLen) + 1);
                    }
                }
            }
        }
        int ans = 1e5;
        for (int pos = 0; pos < rLen; ++pos) ans = min(ans, dp[kLen][pos]);
        return ans;
    }
};