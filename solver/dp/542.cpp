#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
//下面的做法是错误的，按照这样的做法应该要dp1,dp2,dp3,dp4
//class Solution {
//public:
//    vector<vector<int>> ans;
//    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//        int m = mat.size(), n = mat[0].size();
//        vector<vector<int>> dp1(m, vector<int>(n, 0));
//        vector<vector<int>> dp2(m, vector<int>(n, 0));
//
//        //dp1:left and up
//        if (mat[0][0]) dp1[0][0] = 1e5;
//        for (int i = 1; i < m; ++i)  if (mat[i][0]) dp1[i][0] = 1 + dp1[i - 1][0];
//        for (int j = 1; j < n; ++j)  if (mat[0][j]) dp1[0][j] = 1 + dp1[0][j - 1];
//        for (int i = 1; i < m; ++i)
//        {
//            for (int j = 1; j < n; ++j) if (mat[i][j]) dp1[i][j] = 1 + min(dp1[i - 1][j], dp1[i][j - 1]);
//        }
//
//        //dp2:right and down
//        if (mat[m - 1][n - 1]) dp2[m - 1][n - 1] = 1e5;
//        for (int i = m - 2; i >= 0; --i) if (mat[i][n - 1]) dp2[i][n - 1] = 1 + dp2[i + 1][n - 1];
//        for (int j = n - 2; j >= 0; --j) if (mat[m - 1][j]) dp2[m - 1][j] = 1 + dp2[m - 1][j + 1];
//        for (int i = m - 2; i >= 0; --i)
//        {
//            for (int j = n - 2; j >= 0; --j) if (mat[i][j]) dp2[i][j] = 1 + min(dp2[i + 1][j], dp2[i][j + 1]);
//        }
//        ans.clear();
//        for (int i = 0; i < m; ++i)
//        {
//            vector<int> tmp;
//            for (int j = 0; j < n; ++j) tmp.push_back(min(dp1[i][j], dp2[i][j]));
//            ans.push_back(tmp);
//        }
//        return ans;
//    }
//};
//正确做法一：两次dp解决（相对于四次dp的做法常数减半，正确性参见力扣官方题解下的评论区）
class DP_Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1e5));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (!mat[i][j]) dp[i][j] = 0;
        }

        //dp:left and up
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j])
                {
                    if (i != 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (j != 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }

        //dp:right and down
        for (int i = m - 1; i >= 0; --i)
        {
            for (int j = n - 1; j >= 0; --j)
            {
                if (mat[i][j])
                {
                    if (i != m - 1) dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    if (j != n - 1) dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
            }
        }
        return dp;
    }
};
//正确做法二：多源BFS
class BFS_Solution {
public:
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dis(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> que;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (!mat[i][j]) {que.push({i, j}); visited[i][j] = true;}
        }

        while(!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();

            for (int i = 0; i < 4; ++i)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy])
                {
                    dis[xx][yy] = 1 + dis[x][y];
                    visited[xx][yy] = true;
                    que.push({xx, yy});
                }
            }
        }

        return dis;
    }
};