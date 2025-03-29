class Solution {
private:
    void dfs(vector<bool> &col, vector<bool> &left, vector<bool> &right, int pos, int n, int &ans)
    {
        if (pos == n)
        {
            ++ans;
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            //pos行选取第i个位置放置
            if (col[i] || left[pos + i] || right[pos - i + n - 1]) continue;
            col[i] = left[pos + i] = right[pos - i + n - 1] = true;
            dfs(col, left, right, pos + 1, n, ans);
            col[i] = left[pos + i] = right[pos - i + n - 1] = false;
        }
    }
public:
    int totalNQueens(int n) {
        //dfs每次决定当前pos行放在那一列，因此维护
        //col[i] left[i]: i + j 0 ~ 2n - 2 right[i] i - j + n - 1 0 ~ 2n - 2
        vector<bool> col(n, false);
        vector<bool> left(2 * n - 1, false);
        vector<bool> right(2 * n - 1, false);
        int ans = 0;
        dfs(col, left, right, 0, n, ans);
        return ans;
    }
};