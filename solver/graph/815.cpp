class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        //组合数学讲过的超图，先建超图然后BFS应该可以过,起点和终点分别被映射为超图中的多个点
        if (source == target) return 0;
        int n = routes.size();
        vector<vector<bool>> graph(n, vector<bool>(n, false));//routes即超图中每个超点包含的点，而graph则是超点之间的连边,为了简化去重，这里不适用邻接表而是邻接矩阵
        //两个超点之间有连边当且仅当存在原图中的一个点同时在这两个超点内，考虑逆向思维，对于原图中每一个点维护它属于哪一个超点
        unordered_map<int, vector<int>> belong;
        for (int i = 0; i < n; ++i)
        {
            for (auto node : routes[i]) belong[node].push_back(i);
        }
        for (auto [node, vec] : belong)
        {
            for (int i = 0, sz = vec.size(); i < sz; ++i)
            {
                for (int j = i + 1; j < sz; ++j) graph[vec[i]][vec[j]] = graph[vec[j]][vec[i]] = true;
            }
        }
        // for (int i = 0; i < n; ++i) {for (int j = 0; j < n; ++j) cout<<graph[i][j]<<" "; cout<<"\n";}

        queue<int> que;//放超图中的点
        vector<int> dis(n, -1);//兼职visited功能
        for (auto tmp : belong[source]) {que.push(tmp); dis[tmp] = 1;}
        while(!que.empty())
        {
            int curNode = que.front();
            que.pop();
            for (int nextNode = 0; nextNode < n; ++nextNode)
            {
                if (graph[curNode][nextNode] && dis[nextNode] == -1) {dis[nextNode] = 1 + dis[curNode]; que.push(nextNode);}
            }
        }

        int res = 0x7fffffff;
        for (auto tmp : belong[target]) if (dis[tmp] != -1) res = min(res, dis[tmp]);
        return res == 0x7fffffff ? -1 : res;
    }
};