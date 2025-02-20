class Solution {
private:
    static bool cmp(const vector<int> & lhs, const vector<int> & rhs) {return lhs[1] < rhs[1];}
public:
    //模糊的思路：先排序，然后尝试用最长上升子序列的做法来想
    //排序对于数对的第二个数升序排序
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);

        int len = pairs.size(), ans = 1;
        vector<int> dp(len); //0-based
        dp[0] = 1;
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j < i; ++j) if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};