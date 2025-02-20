// class Solution {
// public:
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         if (n == 1) return {0};
//         //朦胧的思路：按照拓扑排序来做
//         vector<int> degree(n, -1);
//         vector<vector<int>> graph(n);
//         for (auto tmp : edges)
//         {
//             ++degree[tmp[0]];
//             ++degree[tmp[1]];
//             graph[tmp[0]].push_back(tmp[1]);
//             graph[tmp[1]].push_back(tmp[0]);
//         }

//         int left = n;
//         vector<int> cur;
//         vector<bool> del(n, false);
//         for (int i = 0; i < n; ++i) if (!degree[i]) cur.push_back(i);

//         while(left > 2)
//         {
//             vector<int> nxt;
//             for (auto node : cur)
//             {
//                 del[node] = true;
//                 --left;
//                 for (auto son : graph[node])
//                 {
//                     if (!del[son] && !--degree[son]) nxt.push_back(son);
//                 }
//             }
//             cur = nxt;
//         }

//         vector<int> res;
//         for (int i = 0; i < n; ++i)
//         {
//             if (!del[i]) res.push_back(i);
//         }

//         return res;
//     }
// };

class Solution {
private:
    //给定一个源点，在图中找到距离这个点最远的点，并以parent形式记录BFS搜索路径
    int findFar(int origin, vector<int> &parent, const vector<vector<int>> &graph)
    {
        queue<int> que;
        vector<int> vis(graph.size(), false);

        que.push(origin);
        vis[origin] = true;

        int res;
        while(!que.empty())
        {
            int sz = que.size();
            for (int i = 0; i < sz; ++i)
            {
                int cur = que.front();
                res = cur;
                que.pop();

                for (auto son : graph[cur])
                {
                    if (!vis[son])
                    {
                        vis[son] = true;
                        parent[son] = cur;
                        que.push(son);
                    }
                }
            }
        }

        return res;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        //找到直径，然后取直径的中点即可

        vector<int> parent(n);
        vector<vector<int>> graph(n);
        for (auto tmp : edges)
        {
            graph[tmp[0]].push_back(tmp[1]);
            graph[tmp[1]].push_back(tmp[0]);
        }
        int x = findFar(0, parent, graph);
        int y = findFar(x, parent, graph);

        // cout<<"x = "<<x<<" y = "<<y<<'\n';
        parent[x] = -1;
        vector<int> line;
        for (int i = y; i != -1; i = parent[i]) line.push_back(i);

        // for (auto t : line) cout<<t<<" ";
        // cout<<'\n';

        int len = line.size();
        if (len % 2 == 1) return {line[len / 2]};
        else return {line[len / 2 - 1], line[len / 2]};
    }
};