class Solution {
        private:
        vector<int> color;
        bool dfs(int cur, vector<vector<int>>& graph)
        {
            int toColor = color[cur] == 1 ? 2 : 1;
            for (auto nxt : graph[cur])
            {
                if (!color[nxt])
                {
                    color[nxt] = toColor;
                    if (!dfs(nxt, graph)) return false;
                }
                else if (color[nxt] == color[cur]) return false;
            }
            return true;
        }
        public:
        Solution() : color(100, 0){}
        bool isBipartite(vector<vector<int>>& graph) {
            if (!graph.size()) return true;
            for (int i = 0, n = graph.size(); i < n; ++i)
            {
                if (!color[i])
                {
                    color[i] = 1;
                    if (!dfs(i, graph)) return false;
                }
            }
            return true;
        }
};