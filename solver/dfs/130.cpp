class Solution {
private:
    const vector<int> dr = {1, -1, 0, 0};
    const vector<int> dc = {0, 0, 1, -1};
    //可以存活的节点赋值为'Y'，然后最终遍历一遍将'Y'恢复为'O'，将'O'修改为'X'
    void dfs(vector<vector<char>>& board, int r, int c)
    {
        int m = board.size();
        int n = board[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') return;
        board[r][c] = 'Y';

        for (int i = 0; i < 4; ++i)
        {
            int new_r = r + dr[i], new_c = c + dc[i];
            dfs(board, new_r, new_c);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // vector<vector<bool>> left(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {dfs(board, i, 0); dfs(board, i, n - 1);}
        for (int j = 0; j < n; ++j) {dfs(board, 0, j); dfs(board, m - 1, j);}

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'Y') board[i][j] = 'O';
            }
        }
    }
};