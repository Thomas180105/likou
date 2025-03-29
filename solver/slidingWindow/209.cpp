class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, len = nums.size(), ans = len + 1;
        int sum = 0;
        for (; r < len; ++r)
        {
            sum += nums[r];
            if (sum >= target)
            {
                while(sum >= target) sum -= nums[l++];
                ans = min(ans, r - l + 2);
            }
        }
        return ans == len + 1 ? 0 : ans;
    }
};