//用时: 1WA1AC 13:09
//可以考虑求解k-largets O(N)优化

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int avr = 0;
        // for (auto tmp : nums) avr += tmp;
        // avr = (avr + nums.size() / 2) / nums.size();
        // int ans = 0;
        // for (auto tmp : nums) ans += abs(tmp - avr);
        // return ans;
        sort(nums.begin(), nums.end());
        int t = nums[nums.size() / 2], ans = 0;
        for (auto tmp : nums) ans += abs(tmp - t);
        return ans;
    }
};