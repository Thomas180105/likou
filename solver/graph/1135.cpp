class Solution {
private:
    class UnionFind{
    private:
        vector<int> fa;
        int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
    public:
        UnionFind(int n) : fa(n + 1)
        {
            for (int i = 1; i <= n; ++i) fa[i] = i;
        }
        bool query(int u, int v) {return find(u) == find(v);}
        void merge(int u, int v) {fa[find(u)] = find(v);}
    };
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        UnionFind hst(n);
        sort(connections.begin(), connections.end(), [](const vector<int>& a, const vector<int>& b) -> bool {return a[2] < b[2];});
        int cnt = 0, ans = 0;
        for (auto curEdge : connections)
        {
            if (!hst.query(curEdge[0], curEdge[1]))
            {
                ans += curEdge[2];
                hst.merge(curEdge[0], curEdge[1]);
                if (++cnt == n - 1) break;
            }
        }
        return cnt == n - 1 ? ans : -1;
    }
};