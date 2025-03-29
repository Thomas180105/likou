class Solution {
private:
    const vector<int> dx = {1, -1, 0, 0};
    const vector<int> dy = {0, 0, 1, -1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //直接用多源BFS
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));//因为是BFS，所以进数据结构的时候就标记visited

        queue<pair<int, int>> que;
        int freshCnt = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1) ++freshCnt;
                else if (grid[i][j] == 2) que.push({i, j});
            }
        }

        int time = 0;
        while(freshCnt && time <= m * n)
        {
            for (int i = 0, qSize = que.size(); i < qSize; ++i)
            {
                auto [x, y] = que.front();
                que.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int newX = x + dx[k], newY = y + dy[k];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        --freshCnt;
                        grid[newX][newY] = 2;
                        que.push({newX, newY});
                    }
                }
            }
            ++time;
        }
        return freshCnt ? -1 : time;
    }
};