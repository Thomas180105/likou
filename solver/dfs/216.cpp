class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp0 = 0, dp1 = -1e5;
        for (auto price : prices)
        {
            int new0 = max(dp0, dp1 + price);
            int new1 = max(dp1, dp0 - price);
            dp0 = new0;
            dp1 = new1;
        }
        return dp0;
    }
};