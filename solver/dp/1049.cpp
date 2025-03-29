class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //手玩一下：1 1 2 4 7 8，总和23，直接dp一下，发现dp[11] = true,所以ans = 12 - 11 = 1
        int sum = 0;
        for (auto s : stones) sum += s;
        vector<bool> dp(sum / 2 + 1, false);
        dp[0] = true;
        for (auto s : stones)
        {
            for (int value = sum / 2; value >= s; --value) dp[value] = dp[value] || dp[value - s];
        }
        int ans = -1;
        for (int i = sum / 2; i >= 0; --i)
        {
            if (dp[i]) {ans = i; break;}
        }
        return sum - 2 * ans;
    }
};