class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int days = temperatures.size();
        vector<int> res(days, 0);
        stack<pair<int, int>> stk;//(value, index)
        for (int i = 0; i < days; ++i)
        {
            int curVal = temperatures[i];
            while(!stk.empty() && stk.top().first < curVal)
            {
                res[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({curVal, i});
        }

        // while(!stk.empty()) {res[stk.top().second] = 0; stk.pop();}

        return res;
    }
};