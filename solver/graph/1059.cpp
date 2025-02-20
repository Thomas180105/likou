//
// Created by Lenovo on 2025/2/20.
//
aclass Solution {
        public:
        bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
            //从终点到起点反着走，拓扑排序
            vector<vector<int>> graph(n);
            vector<int> inDeg(n, 0);
            for (auto tmp : edges)
            {
                graph[tmp[1]].push_back(tmp[0]);
                ++inDeg[tmp[0]];
            }
            if (inDeg[destination]) return false;

            queue<int> que;
            que.push(destination);
            while(!que.empty())
            {
                auto cur = que.front();
                if (cur == source) return true;
                que.pop();
                for (auto son : graph[cur]) if (!--inDeg[son]) que.push(son);
            }
            return false;
        }
};