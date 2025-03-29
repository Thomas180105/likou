class Solution {
public:
    int consecutiveNumbersSum(int n) {
        //爽做小学数学题1 + 2 + .. + n = (n + 1) * n / 2，所以这个题目时间复杂度O(sqrt(n))，10^9的数据随便过
        vector<int> sum(1, 0);
        for (int i = 1; ; ++i)
        {
            int cur = sum.back() + i;
            sum.push_back(cur);
            if (cur > n) break;
        }
        int ans = 0;
        for (int i = 0; n > sum[i]; ++i) ans += ((n - sum[i]) % (i + 1) == 0);
        return ans;
    }
};