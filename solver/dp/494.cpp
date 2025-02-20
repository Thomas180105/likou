class Solution {
private:
    static const int r = 2000;
    static const int bias = 1000;
    bool isLawful(int x) {return x >= 0 && x <= r;}
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int len = nums.size();

        vector<vector<int>> dp(len + 1, vector<int>(r + 1));
        dp[0][0 + bias] = 1;
        for (int i = 1; i <= len; ++i)
        {
            for (int j = 0; j <= r; ++j)
            {
                if (isLawful(j - nums[i - 1])) dp[i][j] += dp[i - 1][j - nums[i - 1]];
                if (isLawful(j + nums[i - 1])) dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }

        return dp[len][target + bias];
    }
};