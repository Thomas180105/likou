class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //首先就是拓扑排序然后dp即可
        //入度为零的点最先处理，他们的祖先列表为空数组。
        //然后开始拓扑排序，curNode对于每一个当前pop出来的sonNode，将curNode以及curNode的祖先全部加入到sonNode的祖先中
        //注意这样完全可能会出现重复添加的情况，所以我们考虑使用set
        vector<set<int>> fa(n);
        vector<vector<int>> graph(n);
        vector<int> inDeg(n, 0);
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            ++inDeg[edge[1]];
        }

        queue<int> que;
        for (int i = 0; i < n; ++i) if (!inDeg[i]) que.push(i);
        while(!que.empty())
        {
            auto curNode = que.front();
            que.pop();

            // cout<<"the curNode = "<<curNode<<'\n';
            // cout<<"and its Ancestors are: ";
            // for (auto t : fa[curNode]) cout<<t<<" ";
            // cout<<'\n';

            for (auto sonNode : graph[curNode])
            {
                if (!--inDeg[sonNode]) que.push(sonNode);
                fa[sonNode].insert(curNode);
                for (auto t : fa[curNode]) fa[sonNode].insert(t);
            }
        }

        vector<vector<int>> ans(n);
        for (int i = 0; i < n; ++i)
        {
            for (auto t : fa[i]) ans[i].push_back(t);
        }

        return ans;
    }
};