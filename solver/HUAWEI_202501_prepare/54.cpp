// 用时：11：21
class Solution {
public:
    void helper(vector<int> &res, vector<vector<int>>& matrix, int row1, int col1, int row2, int col2)
    {
        if (row1 > row2 || col1 > col2) return;
        if (row1 == row2)
        {
            for (int j = col1; j <= col2; ++j) res.push_back(matrix[row1][j]);
            return;
        }
        if (col1 == col2)
        {
            for (int i = row1; i <= row2; ++i) res.push_back(matrix[i][col1]);
            return;
        }

        for (int j = col1; j <= col2; ++j) res.push_back(matrix[row1][j]);
        for (int i = row1 + 1; i <= row2; ++i) res.push_back(matrix[i][col2]);
        for (int j = col2 - 1; j >= col1; --j) res.push_back(matrix[row2][j]);
        for (int i = row2 - 1; i >= col1 + 1; --i) res.push_back(matrix[i][col1]);

        helper(res, matrix, row1 + 1, col1 + 1, row2 - 1, col2 - 1);
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        helper(res, matrix, 0, 0, m - 1, n - 1);
        return res;
    }
};