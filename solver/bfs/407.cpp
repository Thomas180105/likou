class Solution {
private:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    struct cmp{
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first > b.first;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        //前几天刷B站看过这题的解法，思路上很有启发性的一道题，来实现一下
        int m = heightMap.size(), n = heightMap[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;//(rain高度，坐标映射) （x, y）-> x * n + y;
        for (int i = 0; i < m; ++i)
        {
            visited[i][0] = true;
            que.push({heightMap[i][0], i * n + 0});
            visited[i][n - 1] = true;
            que.push({heightMap[i][n - 1], i * n + (n - 1)});
        }
        for (int j = 0; j < n; ++j)
        {
            visited[0][j] = true;
            que.push({heightMap[0][j], j});
            visited[m - 1][j] = true;
            que.push({heightMap[m - 1][j], (m - 1) * n + j});
        }

        int res = 0;
        while(!que.empty())
        {
            auto [x, y] = que.top();
            que.pop();

            // cout<<"####now we pop ("<<y / n<<", "<<y % n<<"), and the cur rain is "<<x<<"\n";

            for (int k = 0; k < 4; ++k)
            {
                int newX = y / n + dx[k], newY = y % n + dy[k];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY])
                {
                    //直接这里写visited就行，这与一般的dijkstra不同，第一次访问一定久可以定下来rain
                    int tmp = max(x, heightMap[newX][newY]);
                    res += tmp - heightMap[newX][newY];
                    visited[newX][newY] = true;
                    que.push({tmp, newX * n + newY});
                    // cout<<"now ("<<newX<<", "<<newY<<") add "<<tmp<<" - "<<heightMap[newX][newY]<<" = "<<tmp - heightMap[newX][newY]<<'\n';
                }
            }
        }
        return res;
    }
};