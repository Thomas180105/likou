#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> reach_p(m, vector<bool>(n, false));
        vector<vector<bool>> reach_a(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {dfs(heights, m, n, i, 0, reach_p); dfs(heights, m, n, i, n - 1, reach_a);}
        for (int i = 0; i < n; ++i) {dfs(heights, m, n, 0, i, reach_p); dfs(heights, m, n, m - 1, i, reach_a);}
        vector<vector<int>> ans;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (reach_a[i][j] && reach_p[i][j]) ans.push_back(vector<int> {i, j});
        }
        return ans;
    }
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    void dfs(const vector<vector<int>> &matrix, int m, int n, int r, int c, vector<vector<bool>> &flag)
    {
        if (flag[r][c]) return;
        flag[r][c] = true;

        for (int i = 0; i < 4; ++i)
        {
            int rr = r + dx[i], cc = c + dy[i];
            if (rr >= 0 && rr < m && cc >= 0 && cc < n && matrix[r][c] <= matrix[rr][cc]) dfs(matrix, m, n, rr, cc, flag);
        }
    }
};