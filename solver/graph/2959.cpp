class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        int res = 0;
        vector<bool> opened(n, false);

        for (int mask = 0; mask < (1 << n); ++mask)//暴力尝试，枚举1024种可能
        {
            for (int i = 0; i < n; ++i) opened[i] = (mask >> i) & 1;
            vector<vector<int>> d(n, vector<int>(n, 1e6));
            for (const auto& road : roads)
            {
                int i = road[0], j = road[1], r = road[2];
                if (opened[i] && opened[j]) d[i][j] = d[j][i] = min(d[i][j], r);
            }

            // Floyd-Warshall algorithm
            for (int k = 0; k < n; ++k)
            {
                if (opened[k])
                {
                    for (int i = 0; i < n; ++i)
                    {
                        if (opened[i]) {
                            for (int j = i + 1; j < n; ++j)
                            {
                                if (opened[j]) d[i][j] = d[j][i] = min(d[i][j], d[i][k] + d[k][j]);
                            }
                        }
                    }
                }
            }

            bool valid = true;
            for (int i = 0; i < n && valid; ++i)
            {
                if (opened[i])
                {
                    for (int j = i + 1; j < n; ++j)
                    {
                        if (opened[j] && d[i][j] > maxDistance)
                        {
                            valid = false;
                            break;
                        }
                    }
                }
            }

            if (valid) ++res;
        }
        return res;
    }
};