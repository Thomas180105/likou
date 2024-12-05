class Solution {
public:
    int candy(vector<int>& ratings) {
        int m = ratings.size();
        vector<int> nums(m, 1);
        for (int i = 1; i < m; ++i) if (ratings[i] > ratings[i - 1]) nums[i] = nums[i - 1] + 1;
        int ans = nums[m - 1];
        for (int i = m - 2; i >= 0; --i)
        {
            if (ratings[i] > ratings[i + 1]) nums[i] = max(nums[i], nums[i + 1] + 1);
            ans += nums[i];
        }
        return ans;
    }
};