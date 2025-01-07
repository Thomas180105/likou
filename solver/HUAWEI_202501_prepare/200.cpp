//用时：9:44
class Solution {
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++cnt;
                    stack<pair<int, int>> stk;
                    stk.push({i, j});


                    while(!stk.empty())
                    {
                        auto [x, y] = stk.top();
                        stk.pop();
                        grid[x][y] = '0';

                        for (int k = 0; k < 4; ++k)
                        {
                            int xx = x + dx[k], yy = y + dy[k];
                            if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1') stk.push({xx, yy});
                        }
                    }


                }
            }
        }
        return cnt;
    }
};