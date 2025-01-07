//用时：3：28
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int dp = nums[0];
        for (int i = 1, len = nums.size(); i < len; ++i)
        {
            if (dp < 0) dp = 0;
            dp += nums[i];
            ans = max(ans, dp);
        }
        return ans;
    }
};