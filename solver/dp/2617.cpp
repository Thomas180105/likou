// class Solution {
// public:
//     //用最暴力的方法先写着
//     int minimumVisitedCells(vector<vector<int>>& grid) {
//         int m = grid.size(), n = grid[0].size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e6));
//         dp[0][0] = 1;
//         for (int i = 0; i < m; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 int k = grid[i][j];
//                 for (int bias = 1; bias <= min(k, m - i - 1); ++bias) dp[i + bias][j] = min(dp[i + bias][j], dp[i][j] + 1);
//                 for (int bias = 1; bias <= min(k, n - j - 1); ++bias) dp[i][j + bias] = min(dp[i][j + bias], dp[i][j] + 1);
//             }
//         }

//         return dp[m - 1][n - 1] == 1e6 ? -1 : dp[m - 1][n - 1];
//     }
// };

//果然TLE，因为最坏可以达到O(m*n*m)，对于题目中的限制，可以达到10^10
//区间修改点查询，可以用带有lazy tag的线段树来做
//对于每一个点相当于是对于它求若干个数的最大值，故而也可以考虑使用优先级队列优化
//最保险的做法就是同时开m + n个优先级队列，这样正确性是保证的，暂时认为这样不会爆空间吧
class Solution {
private:
    struct cmp{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {return a.first > b.first;}
    };
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>> row(m), col(n);//pair:(dp数值，作用范围)
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 1e6));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                while(!row[i].empty() &&row[i].top().second < j) row[i].pop();
                if (!row[i].empty()) dp[i][j] = min(dp[i][j], row[i].top().first);
                while(!col[j].empty() && col[j].top().second < i) col[j].pop();
                if (!col[j].empty()) dp[i][j] = min(dp[i][j], col[j].top().first);
                if (dp[i][j] != 1e6)//简单剪枝一下
                {
                    row[i].push({dp[i][j] + 1, j + grid[i][j]});
                    col[j].push({dp[i][j] + 1, i + grid[i][j]});
                }
            }
        }

        return dp[m - 1][n - 1] == 1e6 ? -1 : dp[m - 1][n - 1];
    }
};
