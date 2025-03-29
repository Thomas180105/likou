class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //一、独立思考部分以及自我否定
        //看到这标题在想最小生成树板子题怎么标hard的
        //读题之后才发现这里要求是路径，那么看起来是用状态压缩dp来维护当前访问过的节点集合
        //看到数据范围节点数在12以内更加确定了状缩dp
        //那首先dp肯定要有一维度来表征当前所经历过的点，但是这样显然信息太少没办法转移，因为不知道线头在哪里没办法继续织毛衣
        //(1)定义：考虑dp[state][curPos]形式，其中state表征的是当前遍历过的点，curPos表示当前所在的节点，dp则为对应状态的最短路径
        //所求即为min{dp[(1 << n) - 1][x] | x < n}
        //(2)初始化很自然dp[1 << i][i] = 0
        //(3)状态转移想的是dp[mask][i] = min{dp[mask ^ (1 << j)][j] + 1 | (mask & (1 << j))且i与j相邻}
        //(4)求解的拓扑序就是外层循环从小到大枚举state，然后对于当前state内层循环是枚举对于i的枚举，这样时间复杂度是O(n^2 * 2 ^ n)
        //但是这样的想法似乎连示例1都过不了，问题出在状态转移上，产生对于答案的贡献的转移路径上涉及dp[{0, 1, 2}][2]到dp[{0, 1, 2}][0]的转移
        //那么这样来看dp的转移中mask的转移可以自转移？那这里的拓扑序是什么？这似乎是和原问题同样困难的问题，不会做了
        //思考20分钟之后看了题解

        //二、看题解之后的困惑
        //题解的定义就是dp[mask][curPos]，但是转移方程是dp[mask][curPos] = min{cur[mask ^ (1 << i)][i] + d[i][j]}，其中d[i][j]是Floyd算法预处理得到的两两之间的最小距离
        //但是有一个很关键的问题，这里mask不可以自转移，那么是如何支持示例一中{0, 1, 2}涉及的自身转移的？
        //或者换一句话来说d[i][j]中如果涉及mask中没有的节点，那么岂不是违背了dp[mask][curPos]，这是如何work的？

        //困惑的解答
        //思考了半天，可以理解为这里的mask是广义的mask，并不是严格表征当前经过了哪些节点，而是说我们按照意愿已经访问过了哪些节点
        //举例来说，比如一个链式的图 0-1-2-3
        //那么dp[{0, 3}][3]=3，其实这里从dp[{0}][0]转移过来的代价d[0][3]途中就已经经过了1和2，但是我们不将其加入到maskh中，因为我们意愿上只是想要将{0}扩充为{0, 3}
        //算法正确性来说，一共有2^n种顺序将n个节点加入mask种，而正确答案一定是其中一个，所以对于结果来说是正确的，但是对于每一个dp，其mask含义都不是狭义上的”经过的子集“。
        //话说回来其实有点像非确定性图灵机那样，先猜测一个加入节点的顺序（NP），然后多项式时间内解决它(P)
        int n = graph.size();
        vector<vector<int>> d(n, vector<int>(n, n));//初始值是n，合法范围是[0, n - 1]
        for (int i = 0; i < n; ++i)
        {
            for (auto j : graph[i]) d[i][j] = 1;
        }
        for (int u = 0; u < n; ++u)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    d[i][j] = min(d[i][j], d[i][u] + d[u][j]);
                }
            }
        }
        vector<vector<int>> dp(1 << n, vector<int>(n, 0x3f3f3f3f));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 0;
        int res = 0x7fffffff, bound = (1 << n) - 1;
        for (int mask = 1; mask <= bound; ++mask)
        {
            for (int i = 0; i < n; ++i)
            {
                if (mask & (1 << i))
                {
                    for (int j = 0; j < n; ++j)
                    {
                        if (i != j && (mask & (1 << j))) dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + d[i][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            cout<<dp[bound][i]<<" ";
            res = min(res, dp[bound][i]);
        }
        return res;
    }
};