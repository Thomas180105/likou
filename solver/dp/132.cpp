class Solution {
private:
    int get(vector<vector<int>> &memory, const vector<vector<int>> &next, int n, int st, int ed)
    {
        if (st >= ed) return 0;
        if (memory[st][ed] != 0x3f3f3f3f) return memory[st][ed];
        for (auto nextPos : next[st])
        {
            if (nextPos > ed) break;
            memory[st][ed] = min(memory[st][ed], get(memory, next, n, nextPos + 1, ed) + (nextPos < ed));
        }
        return memory[st][ed];
    }
public:
    int minCut(string s) {
        //看起来就是见过的两道中等题的拼接，稍微加一个记忆化搜索？
        int sLen = s.size();
        vector<vector<bool>> dp(sLen, vector<bool>(sLen, false));
        for (int i = 0; i < sLen; ++i) dp[i][i] = true;
        for (int i = 0; i < sLen - 1; ++i) dp[i][i + 1] = (s[i] == s[i + 1]);
        for (int len = 3; len <= sLen; ++len)
        {
            for (int st = 0; st + len <= sLen; ++st)
            {
                int ed = st + len - 1;
                dp[st][ed] = (dp[st + 1][ed - 1] && s[st] == s[ed]);
            }
        }
        vector<vector<int>> next(sLen);
        for (int st = 0; st < sLen; ++st)
        {
            for (int ed = st; ed < sLen; ++ed) if (dp[st][ed]) next[st].push_back(ed);
        }
        vector<vector<int>> memory(sLen, vector<int>(sLen, 0x3f3f3f3f));//代表没有写过
        return get(memory, next, sLen, 0, sLen - 1);
    }
};