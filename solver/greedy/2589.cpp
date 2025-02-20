// class Solution {
// public:
//     int findMinimumTime(vector<vector<int>>& tasks) {
//         unordered_map<int, int> timeWeights;
//         for (int i = 0; i < tasks.size(); ++i)
//         {
//             int start = tasks[i][0];
//             int end = tasks[i][1];
//             for (int t = start; t <= end; ++t) timeWeights[t]++;
//         }

//         int cnt = 0;
//         while (true)
//         {
//             int maxWeight = 0;
//             int bestTime = -1;
//             for (auto& entry : timeWeights)
//             {
//                 if (entry.second > maxWeight)
//                 {
//                     maxWeight = entry.second;
//                     bestTime = entry.first;
//                 }
//             }
//             if (maxWeight == 0) break;

//             cnt++;
//             for (int i = 0; i < tasks.size(); ++i)
//             {
//                 int start = tasks[i][0];
//                 int end = tasks[i][1];
//                 if (start <= bestTime && bestTime <=+ end && tasks[i][2] > 0)
//                 {
//                     if (--tasks[i][2] == 0)
//                     {
//                         for (int t = start; t <= end; ++t) --timeWeights[t];
//                     }
//                 }
//             }
//             timeWeights.erase(bestTime);
//         }

//         return cnt;
//     }
// };


class Solution {
private:
    const static int N = 2e3 + 5;
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b) -> bool {return a[1] < b[1];});
        vector<int> work(N, 0);

        int ans = 0;
        for (int i = 0, len = tasks.size(); i < len; ++i)
        {
            int st = tasks[i][0], ed = tasks[i][1], duration = tasks[i][2];
            for (int j = st; j <= ed; ++j) duration -= work[j];
            if (duration < 0) continue;
            for (int j = ed; duration != 0; --j) if (!work[j]) {work[j] = 1; --duration; ++ans;}
        }
        return ans;
    }
};
