class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size();

        //变换中的不变量！线性代数的思想，如果现在非法，怎么变化也不会改变非法性
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((board[0][0] ^ board[i][0] ^ board[0][j] ^ board[i][j])) return -1;
            }
        }

        int rowSum = 0, colSum = 0;
        for (int i = 0; i < n; ++i)
        {
            rowSum += board[0][i];
            colSum += board[i][0];
        }

        if (rowSum != n / 2 && rowSum != (n + 1) / 2) return -1;
        if (colSum != n / 2 && colSum != (n + 1) / 2) return -1;

        //将上述非法性探测修改成下面这个会WA，因为下面这个不充分，不能检查出某些非法状态
        // for (int i = 0; i < n; ++i)
        // {
        //     int sum = 0;
        //     for (int j = 0; j < n; ++j) sum += board[i][j];
        //     if (sum != n / 2 && sum != (n + 1) / 2) return -1;
        // }

        // for (int j = 0; j < n; ++j)
        // {
        //     int sum = 0;
        //     for (int i = 0; i < n; ++i) sum += board[i][j];
        //     if (sum != n / 2 && sum != (n + 1) / 2) return -1;
        // }

        int rowSwap = 0, colSwap = 0;
        for (int i = 0; i < n; ++i)
        {
            rowSwap += board[i][0] == (i % 2);
            colSwap += board[0][i] == (i % 2);
        }

        if (n % 2 == 0)
        {
            rowSwap = min(rowSwap, n - rowSwap);
            colSwap = min(colSwap, n - colSwap);
        }
        else
        {
            if (rowSwap % 2) rowSwap = n - rowSwap;
            if (colSwap % 2) colSwap = n - colSwap;
        }

        return (rowSwap + colSwap) / 2;
    }
};