class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));// dp[i][j]表示开区间(i , j)内气球可以产生的最大收益（1-based）
        vector<int> query(n + 2);
        query[0] = query[n + 1] = 1;
        for (int i = 1; i <= n; ++i) query[i] = nums[i - 1];

        for (int k = 3; k <= n + 2; ++k)
        {
            for (int i = 0; i <= n - k + 2; ++i)
            {
                for (int d = i + 1, j = i + k - 1; d < j; ++d)
                {
                    dp[i][j] = max(dp[i][j], dp[i][d] + dp[d][j] + query[i] * query[d] * query[j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};