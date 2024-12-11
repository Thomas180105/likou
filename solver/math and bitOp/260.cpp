class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int l = nums.size();
        int tot = 0;
        for (auto tmp : nums) tot ^= tmp;

        int tag = 0;
        for (; tag < 32; ++tag) if ((tot>>tag) & 1) break;

        int a = 0, b = 0;
        for (auto tmp : nums)
        {
            if (tmp & (1 << tag)) a ^= tmp;
            else b ^= tmp;
        }

        return {a, b};
    }
};