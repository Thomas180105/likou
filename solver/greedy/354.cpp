// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         //整体来说这个题目其实是之前写过两道题目地综合：
//         //考虑一维的情况，很明显是排序加贪心
//         //对于二维，先对于第一维进行排序，现在我们要处理第二维度
//         //这个时候贪心地每次先尽可能选小的显然是错误的，因为它的下标可能很靠后了。比如 99 100 101 1 2 那么挑小的选只能选出 1 2
//         //直接想到动态规划，这就是最长上升子序列，很标准的dp: dp[i] = max{dp[j] + 1 | envelopes[j] < envelopes[i]}
//         //看到数据范围是1e5，状态转移暴力来是O(1)，炸飞了。
//         //很多先前的状态事实上不可能再转移到后面的任何一个dp上，即如果一个i1它dp值比i2小且高度比i2高，那么i1就被i2挡住了

//         sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
//             return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
//         });
//         //这里需要一个去重，不然比如[1, 2][1, 5]会让答案是2，但实际上是1
//         auto last = unique(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
//             return a[0] == b[0];
//         });
//         envelopes.erase(last, envelopes.end());

//         for (auto t : envelopes) cout<<"("<<t[0]<<", "<<t[1]<<") ";cout<<'\n';

//         int len = envelopes.size();
//         if (len == 0) return 0;
//         vector<int> height;
//         for (int i = 0; i < len; ++i)
//         {
//             if (height.empty() || envelopes[i][1] > height.back()) {height.push_back(envelopes[i][1]); continue;}
//             //这里二分，化转移开销O(N)为O(logN),找到height中第一个大于(不能大于等于)新进来height的index，然后更新其后的值
//             int l = 0, r = height.size();
//             while(l < r)
//             {
//                 int mid = l + (r - l) / 2;
//                 if (height[mid] <= envelopes[i][1]) l = mid + 1;
//                 else r = mid;
//             }//l - 1即为所求, l为第一个大于等于的
//             if (l == height.size()) height.push_back(envelopes[i][1]);
//             else height[l] = envelopes[i][1];
//         }
//         return height.size();
//     }
// };

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //整体来说这个题目其实是之前写过两道题目地综合：
        //考虑一维的情况，很明显是排序加贪心
        //对于二维，先对于第一维进行排序，现在我们要处理第二维度
        //这个时候贪心地每次先尽可能选小的显然是错误的，因为它的下标可能很靠后了。比如 99 100 101 1 2 那么挑小的选只能选出 1 2
        //直接想到动态规划，这就是最长上升子序列，很标准的dp: dp[i] = max{dp[j] + 1 | envelopes[j] < envelopes[i]}
        //看到数据范围是1e5，状态转移暴力来是O(1)，炸飞了。
        //很多先前的状态事实上不可能再转移到后面的任何一个dp上，即如果一个i1它dp值比i2小且高度比i2高，那么i1就被i2挡住了

        //发现不可以去重，比如[[30,50],[12,2],[3,4],[12,15]]和[[30,50],[12,2],[13,3],[12,15]]
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });

        int len = envelopes.size();
        if (len == 0) return 0;
        vector<int> height;
        for (int i = 0; i < len; ++i)
        {
            //这里二分，化转移开销O(N)为O(logN),找到height中第一个大于等于（这里不是严格大于了）新进来height的index，然后更新其后的值
            int l = 0, r = height.size();
            while(l < r)
            {
                int mid = l + (r - l) / 2;
                if (height[mid] < envelopes[i][1]) l = mid + 1;
                else r = mid;
            }
            if (l == height.size()) height.push_back(envelopes[i][1]);
            else height[l] = envelopes[i][1];
        }
        return height.size();
    }
};