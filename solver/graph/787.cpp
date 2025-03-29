// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         //单源最短路，限制了路径的长度
//         //要么就是dijstrak加上一个路径长度的维度，要么就是BFS
//         //但是BFS显得有些奇怪，不好设置visited，先写dp吧
//         // vector<vector<pair<int, int>>> graph(n);//(to, price)
//         // for (auto flight : flights)
//         // {
//         //     graph[flight[0]].push_back({flight[1], flight[2]});
//         // }

//         vector<vector<int>> dis(n, vector<int>(k + 2, 1e9));//dis[i][j]，恰好经过j个节点到达i出所需要的最低费用
//         dis[src][0] = 0;

//         for (int step = 1; step <= k + 1; ++step)
//         {
//             for (auto flight : flights)
//             {
//                 int from = flight[0], to = flight[1], cost = flight[2];
//                 dis[to][step] = min(dis[to][step], dis[from][step - 1] + cost);
//             }
//         }

//         int ans = 1e9;
//         for (int step = 1; step <= k + 1; ++step) ans = min(ans, dis[dst][step]);

//         return ans == 1e9 ? -1 : ans;
//     }
// };


//模拟考试结束之后按照BFS的思路写一发，不设置任何visited
//关键点除了不能设置常规意义上的visited之外，也不能使用类似于if (cost > dis[node]) continue;之类的剪枝，因为现在不只是代价作为衡量因素，也需要考虑中转次数
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //单源最短路，限制了路径的长度
        //要么就是dijstrak加上一个路径长度的维度，要么就是BFS
        //但是BFS显得有些奇怪，不好设置visited，先写dp吧
        vector<vector<pair<int, int>>> graph(n);//(to, price)
        for (auto flight : flights)
        {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> dis(n, 1e9);
        dis[src] = 0;

        queue<pair<int, int>> que;
        que.push({src, 0});//node, cost

        int step = 1;
        while(!que.empty() && step <= k + 1)
        {
            for (int i = 0, qSize = que.size(); i < qSize; ++i)
            {
                auto [node, cost] = que.front();
                que.pop();

                // if (cost > dis[node]) continue;
                for (auto [son, len] : graph[node])
                {
                    if (dis[son] > cost + len)
                    {
                        dis[son] = cost + len;
                        que.push({son, dis[son]});
                    }
                }
            }
            ++step;
        }

        //k = 1
        //0->1->2->3
        //0->2

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};