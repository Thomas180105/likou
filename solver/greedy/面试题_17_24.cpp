class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        //往一维的方向去靠，一个数组求其中最大子序列
        //二维转为一维的话就是一个列方向上的前缀和处理加上一个二层循环
        if (matrix.empty() || matrix[0].empty()) return {};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<long long>> preSum(m, vector<long long>(n + 1, 0));//n行m列，那么就是m个前缀和数组，这里每个前缀和数组1-based
        for (int j = 0; j < m; ++j)
        {
            for (int i = 1; i <= n; ++i) preSum[j][i] = preSum[j][i - 1] + matrix[i - 1][j];
        }

        vector<int> ans;
        int ans_stCol, ans_edCol;
        int ans_stRow, ans_edRow;
        int maxSum = -1e5;
        for (int stRow = 0; stRow < n; ++stRow)
        {
            for (int edRow = stRow; edRow < n; ++edRow)
            {
                long long cur = 0;
                int stCol = 0;
                for (int x = 0; x < m; ++x)//开始在列方向上线性扫
                {
                    if (cur < 0) stCol = x;//应该是这里维护！
                    cur = (preSum[x][edRow + 1] - preSum[x][stRow]) + ((cur >= 0) ? cur : 0);
                    if (cur > maxSum)
                    {
                        maxSum = cur;
                        ans_stRow = stRow, ans_edRow = edRow, ans_stCol = stCol, ans_edCol = x;
                        // stCol = x + 1;//写这行是脑子怎么了！！？？？？
                        // cout<<"an upd: sum = "<<maxSum<<", ans_stRow = "<<ans_stRow<<", ans_edRow = "<<ans_edRow<<", ans_stCol = "<<ans_stCol<<", ans_edCol = "<<ans_edCol<<", and stCol is "<<stCol<<" now\n";
                    }
                }
            }
        }
        return {ans_stRow, ans_stCol, ans_edRow, ans_edCol};
    }
};