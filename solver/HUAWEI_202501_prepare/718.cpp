//用时：08:13
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        //dp为1-based，dp[i][j]表示以i - 1为结尾的num1子数组和以j - 1结尾的num2子数组的最大贡献
        int ans = 0;
        for (int i = 1; i <= len1; ++i)
        {
            for (int j = 1; j <= len2; ++j)
            {
                dp[i][j] = nums1[i - 1] == nums2[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};