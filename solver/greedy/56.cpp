class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //贪心，按照开始时间排序(因为判断当前区间和另一个区间是否重叠的判据中另一个区间的特征是开始时间)，考虑合并
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) -> bool{
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        vector<int> curInterval = intervals[0];
        for (int i = 1, len = intervals.size(); i < len; ++i)
        {
            if (intervals[i][0] <= curInterval[1])
            {
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
            else
            {
                ans.push_back(curInterval);
                curInterval = intervals[i];
            }
        }
        ans.push_back(curInterval);
        return ans;
    }
};