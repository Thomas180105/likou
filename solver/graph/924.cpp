//求强连通分量即可
//scc[i]将节点i映射到对应强连通分量的编号
//member[i]表示编号为强连通分量包含的点的编号
class Solution {
private:
    int sccCnt = 0;

public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int n = graph.size();
        vector<vector<int>> G(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j || !graph[i][j]) continue;
                G[i].push_back(j);
            }
        }

        vector<bool> visited(n, false);
        vector<int> scc(n);
        vector<vector<int>> member;
        for (int cur = 0; cur < n; ++cur)
        {
            if (!visited[cur])
            {
                stack<int> stk;
                stk.push(cur);
                member.push_back({});

                while(!stk.empty())
                {
                    int i = stk.top();
                    stk.pop();

                    if (visited[i]) continue;
                    visited[i] = true;
                    scc[i] = sccCnt;
                    member.back().push_back(i);

                    for (auto j : G[i])
                    {
                        if (!visited[j])
                        {
                            stk.push(j);
                        }
                    }
                }
                ++sccCnt;
            }
        }

        unordered_set<int> query;
        for (auto t : initial) query.insert(t);
        vector<int> toCompare;//存放scc编号
        vector<int> scc2node(sccCnt, -1);
        for (int i = 0; i < sccCnt; ++i)
        {
            // bool flag = false, node = -1;
            bool flag = false;
            int node = -1;
            for (auto sccMember : member[i])
            {
                if (query.count(sccMember))
                {
                    if (!flag) {flag = true; node = sccMember;}
                    else {flag = false; node = -1; break;}
                }
            }
            if (flag) {toCompare.push_back(i); scc2node[i] = node;;}
        }

        int ansNode = 1e5, sz = -1;

        if (toCompare.empty())
        {
            for (auto t : initial) ansNode = min(ansNode, t);
            return ansNode;
        }

        for (auto tmp : toCompare)
        {
            int tmpSz = member[tmp].size();
            if (sz < tmpSz)
            {
                cout<<"[1]\n";
                sz = tmpSz;
                ansNode = scc2node[tmp];
            }
            else if (sz == tmpSz && ansNode > scc2node[tmp]) {cout<<"[2]\n";ansNode = scc2node[tmp];}
        }

        //下面这个会出问题，因为int和size_t比较大小的时候int会类型提升为size_t,悲剧！
        // for (auto tmp : toCompare)
        // {
        //     if (sz < member[tmp].size())
        //     {
        //         cout<<"[1]\n";
        //         sz = member[tmp].size();
        //         ansNode = scc2node[tmp];
        //     }
        //     else if (sz == member[tmp].size() && ansNode > scc2node[tmp]) {cout<<"[2]\n";ansNode = scc2node[tmp];}
        // }

        return ansNode;
    }
};
