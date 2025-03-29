class Solution {
private:
    void dfs(int x, int y, int n, int m, vector<vector<bool>> &filled, int &ans, int cnt)
    {
        if (cnt > ans) return;//剪枝
        if (x == n) {ans = cnt; return;}
        if (y == m) {dfs(x + 1, 0, n, m, filled, ans, cnt); return;}

        if (filled[x][y]) {dfs(x, y + 1, n, m, filled, ans, cnt); return;}
        //处理当前(x, y)处的格子，枚举可能的正方形大小
        for (int sz = 1, maxSz = min(n - x, m - y); sz <= maxSz; ++sz)
        {
            //看看当前大小是否是可行的
            //如果可行，修改filled，往下递归，然后回溯
            bool flag = true;
            for (int i = x; i < x + sz && flag; ++i)
            {
                for (int j = y; j < y + sz; ++j) if (filled[i][j]) {flag = false; break;}
            }
            if (!flag) break;//剪枝
            for (int i = x; i < x + sz && flag; ++i)
            {
                for (int j = y; j < y + sz; ++j) filled[i][j] = true;
            }
            dfs(x, y + 1, n, m, filled, ans, cnt + 1);
            for (int i = x; i < x + sz && flag; ++i)
            {
                for (int j = y; j < y + sz; ++j) filled[i][j] = false;
            }
        }
    }
public:
    int tilingRectangle(int n, int m) {
        int tn = n, tm = m, bound = 0;
        while(tn && tm)
        {
            if (tn >= tm) tn -= tm;
            else tm -= tn;
            ++bound;
        }

        vector<vector<bool>> filled(n, vector<bool>(m, false));
        dfs(0, 0, n, m, filled, bound, 0);
        return bound;
    }
};