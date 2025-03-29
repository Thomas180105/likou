// class Solution {
// public:
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         //第一眼是dp，看了一眼fuel和target值域，那么dp肯定不能直接在这两个值域上去做
//         //猜一个dp:dp[curPos][cnt]表示达到curPos且累计使用cnt次加油时，最多剩余多少油量
//         //curPos = 0即为在起点，然后是表示statation下标，最后一个代表target
//         //初始化:dp[0][0] = startFuel, dp[0][i] = -1(防止从这里转移)
//         //转移:dp[i][j] = (1)dp[i - 1][j]够撑过来，可以转移（2）dp[i - 1][j - 1]够撑过来，且在这一战加油
//         //求解顺序：i为主循环从小到大，j内循环从小到大
//         //答案:dp[targetPos][i]，i从小到大枚举到statations.size()，取其中最小的一个使得dp[][]为非负数

//         int sLen = stations.size();
//         vector<vector<long long>> dp(sLen + 2, vector<long long>(sLen + 1, -1));
//         vector<long long> query(1, 0);
//         for (auto tmp : stations) query.push_back(tmp[0]);
//         dp[0][0] = startFuel;

//         for (int i = 1; i <= sLen; ++i)
//         {
//             bool flag = false;
//             for (int j = 0; j <= i; ++j)
//             {
//                 if (dp[i - 1][j] != -1 && dp[i - 1][j] >= (query[i] - query[i - 1]))
//                 {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j] - (query[i] - query[i - 1])); flag = true;
//                 }
//                 if (j && dp[i - 1][j - 1] != -1 && dp[i - 1][j - 1] >= (query[i] - query[i - 1]))
//                 {
//                     dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - (query[i] - query[i - 1]) + stations[i - 1][1]); flag = true;
//                 }
//             }
//             if (!flag) break;//加了这个剪枝还是程序执行用时倒数5%，晚些时候康康题解咋做
//         }
//         int ans = -1;
//         for (int j = 0; j <= sLen; ++j)
//         {
//             if (dp[sLen][j] >= (target - query.back())) {ans = j; break;}
//         }
//         return ans;
//     }
// };

//看完题解之后交一发贪心，延迟决策的思路领略一下
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        stations.push_back({target, 0});
        int n = stations.size();
        priority_queue<int> queue;

        for (size_t i = 0; i < n; i++)
        {
            while (startFuel < stations[i][0])
            {
                if (queue.empty()) return -1;
                startFuel += queue.top();
                queue.pop();
            }
            queue.push(stations[i][1]);
        }

        return n - queue.size();
    }
};