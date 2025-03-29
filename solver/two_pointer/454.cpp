class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> ans;
        for (int level = 0; level <= m + n - 2; ++level)
        {
            if (level % 2)//i从小到大,同时满足i + j = level
            {
                for (int i = max(0, level - n + 1); i <= min(m - 1, level); ++i) // 0 <= i <= m - 1 && 0 <= level - i <= n - 1
                {
                    ans.push_back(mat[i][level - i]);
                }
            }
            else
            {
                for (int i = min(m - 1, level); i >= max(0, level - n + 1); --i)
                {
                    ans.push_back(mat[i][level - i]);
                }
            }
        }

        return ans;
    }
};