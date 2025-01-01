class Solution {
private:
    class UnionFind{
        //每一个元素都是int
    public:
        int siz;
        vector<int> fa;
        UnionFind(int s): siz(s), fa(siz) {for (int i = 0; i < s; ++i) fa[i] = i;}

        int find(int u) {return fa[u] == u ? u : fa[u] = find(fa[u]);}
        void link(int u, int v) {fa[find(u)] = find(v);}
        bool isUnion(int u, int v) {return find(u) == find(v);}
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind helper(edges.size() + 1);

        vector<int> ans;
        for (auto tmp : edges)
        {
            if (helper.isUnion(tmp[0], tmp[1])) {ans = tmp; break;}
            helper.link(tmp[0], tmp[1]);
        }
        return ans;
    }
};