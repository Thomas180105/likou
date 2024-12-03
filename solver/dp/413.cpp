class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        //dp[i](1-based)：以nums[i - 1]结尾的等差子数组个数
        int n = nums.size();
        if (n <= 2) return 0;

        // vector<int> dp(n + 1);
        int ans = 0;
        int pre = 0, cur;//dp[1] = dp[2] = 0;
        for (int i = 3; i <= n; ++i) {ans += (cur = (nums[i - 2] * 2 == nums[i - 1] + nums[i - 3]) ? pre + 1 : 0); pre = cur;}
        return ans;
    }
};