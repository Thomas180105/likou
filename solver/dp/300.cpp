class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int len = nums.size();
        // vector<int> dp(len + 1, 0);
        // int ans = 0;
        // for (int i = 1; i <= len; ++i)
        // {
        //     dp[i] = 1;
        //     for (int j = 1; j < i; ++j)
        //     {
        //         if (nums[i - 1] > nums[j - 1]) dp[i] = max(dp[i], 1 + dp[j]);
        //     }
        //     ans = max(ans, dp[i]);
        // }
        // return ans;
        int len = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < len; ++i)
        {
            if (nums[i] > dp.back()) dp.push_back(nums[i]);
            else
            {
                auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
                *it = nums[i];
            }
        }
        return dp.size();
    }
};