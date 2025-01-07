//用时: 5:07
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        for (auto tmp : bookings)
        {
            diff[tmp[0] - 1] += tmp[2];
            diff[tmp[1]] -= tmp[2];
        }

        vector<int> res(n);
        res[0] = diff[0];
        for (int i = 1; i < n; ++i) res[i] = res[i - 1] + diff[i];
        return res;
    }
};