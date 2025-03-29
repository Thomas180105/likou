class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        //由于不是四周走，先分析一下，如果有拓扑序可以直接考虑dp
        //从上右 右 下右转移过来，那拓扑序直接按照列来就行
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(m, 0);//最右边相当于没有走法了
        for (int j = n - 2; j >= 0; --j)
        {
            vector<int> newDp(m, 0);
            for (int i = 0; i < m; ++i)
            {
                if (i - 1 >= 0 && grid[i][j] < grid[i - 1][j + 1]) newDp[i] = max(newDp[i], dp[i - 1] + 1);
                if (grid[i][j] < grid[i][j + 1]) newDp[i] = max(newDp[i], dp[i] + 1);
                if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1]) newDp[i] = max(newDp[i], dp[i + 1] + 1);
            }
            dp = newDp;
        }
        int ans = 0;
        for (auto t : dp) ans = max(ans, t);
        return ans;
    }
};