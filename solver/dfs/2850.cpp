// class Solution {
// private:
//     int n = 3;
//     vector<int> dx = {1, -1, 0, 0};
//     vector<int> dy = {0, 0, 1, -1};
// public:
//     int minimumMoves(vector<vector<int>>& grid) {
//         //看起来是一个多源BFS，而且填坑了之后就不可以继续扩散
//         //当两个仍然在扩散的波浪同时遇到一个空格的时候，他们随便哪一个填坑都是一样的

//         queue<pair<int, int>> que;//(x * n + y, cost)
//         int cnt = 0;
//         vector<bool> flag(10, false);
//         for (int i = 0; i < n; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 for (int time = 1; time <= grid[i][j] - 1; ++time)
//                 {
//                     que.push({cnt * 100 + i * n + j, 0});
//                     flag[cnt] = true;
//                     ++cnt;
//                 }
//             }
//         }

//         int total = 0;
//         vector<vector<bool>> visited(n ,vector<bool>(n, false));
//         while(cnt)
//         {
//             int curSz = que.size();
//             for (int i = 0; i < curSz && cnt; ++i)
//             {
//                 auto [position, cost] = que.front();
//                 que.pop();

//                 int tag = position / 100;
//                 if (!flag[tag]) continue;
//                 position %= 100;

//                 int x = position / n, y = position % n;
//                 //visited[x][y] = true;//到这一level才标记visited，防止多个波源不能同时到达同一个坑
//                 if (grid[x][y] == 0)
//                 {
//                     grid[x][y] = 1;
//                     --cnt;
//                     total += cost;
//                     flag[tag] = false;
//                     cout<<"cost = "<<cost<<", x = "<<x<<", y = "<<y<<'\n';
//                     continue;
//                 }

//                 // cout<<"form ("<<x<<", "<<y<<")->"<<cost<<", we get:\n";
//                 for (int j = 0; j < 4; ++j)
//                 {
//                     int newX = x + dx[j], newY = y + dy[j];
//                     if (newX >= 0 && newX < n && newY >= 0 && newY < n /*&& !visited[newX][newY]*/)
//                     {
//                         que.push({100 * tag + newX * n + newY, cost + 1});
//                         // cout<<"("<<newX<<", "<<newY<<")->"<<cost + 1<<"\n";
//                     }
//                 }
//             }
//         }
//         return total;
//     }
// };

//看题解之后抛弃多源BFS的错误思路，花13min实现的究极暴力算法
class Solution {
private:
    int n = 3;
    void dfs(vector<vector<pair<int, int>>> &possible, const vector<pair<int, int>> &origin, vector<bool> &visited, vector<pair<int, int>> &cur)
    {
        if (cur.size() == origin.size())
        {
            possible.push_back(cur);
            return;
        }

        for (int i = 0, len = origin.size(); i < len; ++i)
        {
            if (visited[i] || (i && origin[i] == origin[i - 1] && !visited[i - 1])) continue;

            visited[i] = true;
            cur.push_back(origin[i]);
            dfs(possible, origin, visited, cur);
            visited[i] = false;
            cur.pop_back();
        }
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> less;//i * n + j
        vector<pair<int, int>> more;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0) less.emplace_back(i, j);
                else
                {
                    for (int k = 1; k <= grid[i][j] - 1; ++k) more.emplace_back(i, j);
                }
            }
        }

        vector<vector<pair<int, int>>> possible;
        vector<pair<int, int>> tmp;
        vector<bool> visited(more.size(), false);
        dfs(possible, more, visited, tmp);

        int cost = 0x7fffffff;
        for (auto layout : possible)
        {
            int localCost = 0;
            for (int i = 0, len = layout.size(); i < len; ++i)
            {
                localCost += (abs(layout[i].first - less[i].first) + abs(layout[i].second - less[i].second));
            }
            cost = min(cost, localCost);
        }
        return cost;
    }
};