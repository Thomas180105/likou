class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        //看起来是某种贪心或者动态规划
        //直接上动态规划吧，思考量小一些，cut的大小是100，所以随便上三维dp或者二维dp线性转移
        //cut先排序，
        //dp[i][j][k]，处理cut[i] ~ cut[j]之内的cut，且最后一次是k的最小开销。注意这里的(i, j)是开区间，同时下标认为是1-based，ans = min{dp[0][cuts.size() + 1][x]}
        int cLen = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int> query(cLen + 2);
        for (int i = 0; i < cLen; ++i) query[i + 1] = cuts[i];
        query[0] = 0, query[cLen + 1] = n;
        vector<vector<int>> dp(cLen + 2, vector<int>(cLen + 2, 0));
        for (int len = 2; len <= cLen + 1; ++len)
        {
            for (int st = 0; st + len <= cLen + 1; ++st)
            {
                int ed = st + len;
                dp[st][ed] = 0x7fffffff;
                for (int x = st + 1; x < ed; ++x) dp[st][ed] = min(dp[st][ed], dp[st][x] + dp[x][ed] + (query[ed] - query[st]));
            }
        }
        return dp[0][cLen + 1];
    }
};