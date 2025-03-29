class Solution {
private:
    const vector<int> dx = {1, -1, 0, 0};
    const vector<int> dy = {0, 0, 1, -1};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //很有dp的冲动，但是显然这里不具有无后效性，不过按照特定的顺序（拓扑序）来求解就行
        //那一眼考虑建图，看起来BFS或者记忆化dfs均可。这里写BFS试试，拓扑排序写法应该等效bfs，很久么写了，那这里就写拓扑排序热热手

        //从示例来看是要严格递增，那就是较小的值有一条指向较大值的边
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> outDeg(m ,vector<int>(n, 0));
        for (int x = 0; x < m; ++x)
        {
            for (int y = 0; y < n; ++y)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int newX = x + dx[k], newY = y + dy[k];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[x][y] < matrix[newX][newY]) ++outDeg[x][y];
                }
            }
        }

        queue<pair<int, int>> que;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) if (!outDeg[i][j]) que.push({i, j});
        }

        int ans = 0;
        for (; !que.empty(); ++ans)
        {
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i)
            {
                auto [x, y] = que.front();
                que.pop();

                for (int k = 0; k < 4; ++k)
                {
                    int newX = x + dx[k], newY = y + dy[k];
                    if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[x][y] > matrix[newX][newY] && !--outDeg[newX][newY]) que.push({newX, newY});
                }
            }
        }
        return ans;
    }
};