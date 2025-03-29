class Solution {
private:
    struct status{
        int x, y, left;
        status() {}
        status(int x, int y, int left): x(x), y{y}, left(left) {}
    };
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        //记得大一的时候看过这题，但是忘记怎么做了，直接看的题解之后实现的
        int m = grid.size(), n = grid[0].size();
        if (k >= m + n - 3) return m + n - 2;

        bool visited[m][n][k + 1];
        memset(visited, false, sizeof(visited));
        queue<status> que;
        que.push({0, 0, k});
        visited[0][0][k] = true;

        for (int step = 1; !que.empty(); ++step)
        {
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i)
            {
                auto cur = que.front();
                que.pop();

                for (int j = 0; j < 4; ++j)
                {
                    int nx = cur.x + dx[j], ny = cur.y + dy[j];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] == 0 && !visited[nx][ny][cur.left])
                    {
                        visited[nx][ny][cur.left] = true;
                        if (nx == m - 1 && ny == n - 1) return step;
                        que.push({nx, ny, cur.left});
                    }
                    else if (grid[nx][ny] == 1 && cur.left && !visited[nx][ny][cur.left - 1])
                    {
                        visited[nx][ny][cur.left - 1] = true;
                        if (nx == m - 1 && ny == n - 1) return step;
                        que.push({nx, ny, cur.left - 1});
                    }
                }
            }
        }

        return -1;
    }
};//
// Created by Lenovo on 2025/3/29.
//
