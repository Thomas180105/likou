class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareBySecond);
        int m = intervals.size();
        vector<int> candidate = intervals[0];
        int ans = 1, index = 1;
        while(index < m)
        {
            while(index < m && intervals[index][0] < candidate[1]) ++index;
            if (index < m) {++ans; candidate = intervals[index++];}
        }
        return m - ans;
    }
private:
    static bool compareBySecond(const std::vector<int>& a, const std::vector<int>& b) {
        return a[1] < b[1];
    }
};