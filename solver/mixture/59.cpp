class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        //分解为子问题，按照层次来填数字，一共填写(n + 1) / 2层，对于每层，计算出当前的左上右上右下左下即可正确填写
        int cnt = 0;
        for (int slice = 0; slice < (n + 1) / 2; ++slice)
        {
            //左上为（slice, slice）,边长为n - 2 * slice
            //int sz = n - 2 * slice
            //(slice, slice) -> (slice, slice + sz - 1)
            //(slice + 1, slice + sz - 1) -> (slice + sz - 1, slice + sz - 1)
            //(slice + sz - 1, slice + sz - 2) -> (slice + sz - 1, slice)
            //(slice + sz - 2, slice) -> (slice + 1, slice)

            int sz = n - 2 * slice;
            for (int j = slice; j <= slice + sz - 1; ++j) ans[slice][j] = ++cnt;
            for (int i = slice + 1; i <= slice + sz - 1; ++i) ans[i][slice + sz - 1] = ++cnt;
            for (int j = slice + sz - 2; j >= slice; --j) ans[slice + sz - 1][j] = ++cnt;
            for (int i = slice + sz - 2; i >= slice + 1; --i) ans[i][slice] = ++cnt;
        }
        return ans;
    }
};