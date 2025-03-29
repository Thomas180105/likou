//下面是第一次见到这道题目的思路，虽然行不通，但是可以记录一下自己思路和题解的差距方便下次对齐
//考虑一段一段来处理
//子问题：给l以及k，求从[0, ..., n - 1]中选数填满这l的格子使得逆序对数是k的选取方案数
//理想的是前面一段具体在n个数中选了哪几个不重要，只要统计其贡献的逆序对数然后往后传就行，这样每次只需要知道当前有几个数可以选以及需要达成的逆序对数即可。但是上面这个过程其实是需要知道当前子区间选了哪些数字，这样下去还是不能高效转移

//搁置了一周来看还是比较卡壳，最终看了题解
//题解通过逐位置处理而不是逐区间处理来规避了上面的问题。dp[i][j]：[0, ..., i]构成的排列，逆序对为j的可行个数
class Solution {
private:
    int mod = 1e9 + 7;
    int dfs(int end, int cnt, unordered_map<int, int> &hash, vector<vector<int>> &dp)//由于很多状态不会有用，这里写成记忆化搜索
    {
        if (dp[end][cnt] != -1) return dp[end][cnt];
        if (hash.find(end - 1) == hash.end())//没有约束，那么就是自然转移dp[end][cnt] = dp[end - 1][cnt - i]，其中i <= cnt,同时最后一个数字最多参与贡献end个逆序对
        {
            int tmp = 0;
            for (int i = 0, bound = min(cnt, end); i <= bound; ++i) tmp = (tmp + dfs(end - 1, cnt - i, hash, dp)) % mod;
            dp[end][cnt] = tmp;
        }
        else//有约束，则end - 1处的逆序对数目是固定的数字hash[end - 1], 则cnt在(hash[end - 1], hash[end - 1] + end)范围内有方案，否则无解
        {
            dp[end][cnt] = (cnt >= hash[end - 1] && cnt <= hash[end - 1] + end) ? dfs(end - 1, hash[end - 1], hash, dp) : 0;
        }
        return dp[end][cnt];
    }
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        sort(requirements.begin(), requirements.end(), [](const vector<int> &a, const vector<int> &b) -> bool {
            return a[0] < b[0];
        });
        int maxReq = requirements.back()[1];
        unordered_map<int, int> hash;
        for (auto p : requirements)
        {
            hash[p[0]] = p[1];
            if (p[1] > maxReq) return 0;
        }
        vector<vector<int>> dp(n, vector<int>(maxReq + 1, -1));
        for (int i = 1; i <= maxReq; ++i) dp[0][i] = 0;
        dp[0][0] = 1;
        return dfs(n - 1, maxReq, hash, dp);
    }
};