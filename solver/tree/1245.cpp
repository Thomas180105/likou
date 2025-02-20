class Solution {
private:
    void bfs(const vector<vector<int>> &graph, int start, int &end, int &dist)
    {
        dist = -1;
        int n = graph.size();
        vector<bool> visited(n, false);
        queue<int> que;

        que.push(start);
        visited[start] = true;

        while(!que.empty())
        {
            for (int i = 1, qSize = que.size(); i <= qSize; ++i)
            {
                int cur = que.front();
                que.pop();
                end = cur;

                for (auto son : graph[cur])
                {
                    if (!visited[son])
                    {
                        visited[son] = true;
                        que.push(son);
                    }
                }
            }
            ++dist;
        }
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n);
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int end1, end2, dist1, dist2;
        bfs(graph, 0, end1, dist1);
        bfs(graph, end1, end2, dist2);
        cout<<end1<<" "<<dist1<<'\n';
        cout<<end2<<" "<<dist2<<'\n';
        return dist2;
    }
};