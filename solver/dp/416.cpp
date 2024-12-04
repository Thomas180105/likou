class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // int n = nums.size();
        // int s = 0;
        // for (int i = 0; i < n; ++i) s += nums[i];
        // if (s % 2) return false;
        // vector<vector<bool>> dp(n + 1, vector<bool>(s / 2 + 1, false));
        // //dp[i][j],前i-1个数字中选取总和为j的子数组是否可行

        // for (int i = 0; i <= n; ++i) dp[i][0] = true; 
        // for (int i = 1; i <= n; ++i)
        // {
        //     int tmp = nums[i - 1];
        //     // for (int j = s / 2; j >= tmp; --j) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - tmp];
        //     for (int j = s / 2; j >= tmp; --j) dp[i][j] = dp[i - 1][j] || dp[i - 1][j - tmp];
        //     for (int j = tmp - 1; j >= 0; --j) dp[i][j] = dp[i - 1][j];
        // }

        // return dp[n][s / 2];
        int n = nums.size();
        int s = 0;
        for (int i = 0; i < n; ++i) s += nums[i];
        if (s % 2) return false;

        vector<bool> dp(s / 2 + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = s / 2; j >= nums[i - 1]; --j) dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
        return dp[s / 2];
    }
};