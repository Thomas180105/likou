class Solution {
private:
    int vec2num(const vector<int> &vec)
    {
        int ans = 0;
        long long base = 1;
        for (int i = 0; i < 31; ++i)
        {
            if (vec[i]) ans += base;
            base *= 2;
        }
        return ans;
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //求解最短，且是连续数组，数据范围2e5考虑滑动窗口
        //但是问题在于这里异或没有逆运算
        //那就统计31位上每一位含有1的数量，这样加法是有逆运算的

        int l = 0, r = 0, len = nums.size();
        vector<int> counter(31, 0);
        int ans = 0x7fffffff;
        for (; r < len ; ++r)//考虑把r加进来
        {
            for (int i = 0; i < 31; ++i) if ((nums[r] >> i) & 1) ++counter[i];
            while(vec2num(counter) >= k && l <= r)
            {
                ans = min(ans, r - l + 1);
                for (int i = 0; i < 31; ++i) if ((nums[l] >> i) & 1) --counter[i];
                ++l;
            }
        }

        return ans == 0x7fffffff ? -1 : ans;
    }
};