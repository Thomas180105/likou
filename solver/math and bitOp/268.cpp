class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 1, n = nums.size(); i <= n; ++i) res ^= i;
        for (auto tmp : nums) res ^= tmp;
        return res;
    }
};