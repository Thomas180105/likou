class Solution {
public:
    //def:dp[i](1-based)表示前i个房屋最多能够偷窃到的金额
    //由于转移比较简单，这里简化为O(1)空间
    int rob(vector<int>& nums) {
        // int n = nums.size();
        // if(!n) return 0;
        // if (n == 1) return nums[0];
        // nums.push_back(0);//as dp[n]
        // nums[1] = max(nums[1], nums[0]);
        // for (int i = 2; i <= n; ++i) nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        // return nums[n];
        int n = nums.size();
        if (!n) return 0;
        if (n == 1) return nums[0];
        int pre1 = nums[0], pre2 = max(nums[0], nums[1]), cur = pre2;//注意n = 2时后面的for循环不会执行，所以要赋初值
        for (int i = 3; i <= n; ++i) {cur = max(pre2, pre1 + nums[i - 1]); pre1 = pre2; pre2 = cur;}
        return cur;
    }
};