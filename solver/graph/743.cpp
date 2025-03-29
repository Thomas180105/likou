class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //单源，且没有负权边，直接用dijkstra
        vector<vector<pair<int, int>>> graph(n + 1);//(cost, to)
        for (auto time : times)
        {
            int from = time[0], to = time[1], cost = time[2];
            graph[from].emplace_back(cost, to);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        que.emplace(0, k);
        vector<int> dis(n + 1, 1e9);
        dis[k] = 0;

        while(!que.empty())
        {
            auto [preCost, node] = que.top();
            que.pop();

            if (preCost > dis[node]) continue;
            for (auto [cost, son] : graph[node])
            {
                if (dis[son] > dis[node] + cost)
                {
                    dis[son] = dis[node] + cost;
                    que.emplace(dis[son], son);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (dis[i] == 1e9)
            {
                ans = -1;
                break;
            }
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};