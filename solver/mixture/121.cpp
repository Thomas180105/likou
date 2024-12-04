class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMin = 1e5;
        int ans = 0, curMax = 0;
        for (auto p : prices)
        {
            if (p < curMin)
            {
                ans = max(ans, curMax - curMin);
                curMin = p;
                curMax = 0;
            }
            else if (p > curMax) curMax = p;
        }
        ans = max(ans, curMax - curMin);
        return ans;
    }
};