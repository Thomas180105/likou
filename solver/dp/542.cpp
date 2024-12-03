#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dp1(m, vector(n, 0));
        vector<vector<int>> dp2(m, vector(n, 0));

        //dp1:left and up
        if (mat[0][0]) dp1[0][0] = 1e5;
        for (int i = 1; i < m; ++i)  if (mat[i][0]) dp1[i][0] = 1 + dp1[i - 1][0];
        for (int j = 1; j < n; ++j)  if (mat[0][j]) dp1[0][j] = 1 + dp1[0][j - 1];
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j) if (mat[i][j]) dp1[i][j] = 1 + min(dp1[i - 1][j], dp1[i][j - 1]);
        }

        //dp2:right and down
        if (mat[m - 1][n - 1]) dp2[m - 1][n - 1] = 1e5;
        for (int i = m - 2; i >= 0; --i) if (mat[i][n - 1]) dp2[i][n - 1] = 1 + dp2[i + 1][n - 1];
        for (int j = n - 2; j >= 0; --j) if (mat[m - 1][j]) dp2[m - 1][j] = 1 + dp2[m - 1][j + 1];
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j) if (mat[i][j]) dp2[i][j] = 1 + min(dp2[i + 1][j], dp2[i][j + 1]);
        }
        ans.clear();
        for (int i = 0; i < m; ++i)
        {
            vector<int> tmp;
            for (int j = 0; j < n; ++j) tmp.push_back(min(dp1[i][j], dp2[i][j]));
            ans.push_back(tmp);
        }
        return ans;
    }
};