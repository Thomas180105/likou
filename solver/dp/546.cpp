// class Solution {
// public:
//     int removeBoxes(vector<int>& boxes) {
//         //首先贪心肯定是错的，那比如11112211111111
//         //那我们只能考虑dp。但是dp[][]存储的信息似乎是不够的，不够支持状态转移，
//         //直接数值求解更加扑朔迷离
//         //还是回到dp上，dp[i][j][k]表示[i, j]区间，且最后一次合并是k颜色的最大收益
//         //举例来说2212112那么k = 2的时候，其实并不知道最后一步合并了几个2，这对于状态转移带来了困难
//         //最大的问题就是，子区间的最优解能不能转移到下一个区间（指左右端点只有一个不同且只差1）？，比如32234
//         //太复杂了，甚至都在考虑dp[i][j][n][m]表示区间[i, j]之间最后一次是m个颜色n合并的情况了
//         //现在的想法是记忆化搜索+dp[][][][]往下想。或者从贪心和数值求解的方式往下想（想了想还是觉得太复杂，作罢）
//         //其实我发现dp的转移它是仅依赖于相邻子集，所以可以考虑降维到dp[i][n][m]，表示区间从0开始一共i个数字构成的区间最后一次是合并m个n颜色的最大收益
// };

class Solution {
private:
    int get(vector<int> &boxes, vector<vector<vector<int>>> &dp, int i, int j, int k)
    {
        if (i > j) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int rValue = boxes[j];
        int newJ = j, newK = k;
        while(newJ > i && boxes[newJ - 1] == boxes[newJ]) {++newK; --newJ;}

        dp[i][j][k] = get(boxes, dp, i, newJ - 1, 0) + (newK + 1) * (newK + 1);
        for (int index = i; index < newJ; ++index)
        {
            if (boxes[index] == boxes[newJ]) {
                dp[i][j][k] = max(dp[i][j][k], get(boxes, dp, i, index, newK + 1) + get(boxes, dp, index + 1, newJ - 1, 0));
            }
        }

        return dp[i][j][k];
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int len = boxes.size();
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(len, -1)));
        return get(boxes, dp, 0, len - 1, 0);
    }
};