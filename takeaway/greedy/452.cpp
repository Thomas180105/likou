class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int m = points.size();
        sort(points.begin(), points.end(), cmp);
        int index = 1, ans = 1, cur = points[0][1];
        while(index < m)
        {
            while(index < m && points[index][0] <= cur) ++index;
            if (index < m) {++ans; cur = points[index][1];}
        }
        return ans;
    }
private:
    static bool cmp(const vector<int> &a, const vector<int> &b){
        return a[1] < b[1];
    }
};