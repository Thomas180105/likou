class Solution {
public:
    int maximalRectangle(vector<string>& matrix) {
        int m = matrix.size(), n = m ? matrix[0].size() : 0;
        if (!m || !n) return 0;
        vector<int> height(n, 0);

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) height[j] = (matrix[i][j] == '1') ? height[j] + 1 : 0;
            stack<int> stk;
            vector<int> left(n, -1);//存储左边第一个小于当前元素的下标
            vector<int> right(n, n);
            for (int j = 0; j < n; ++j)
            {
                //入栈时更新信息，这样栈里面需要单调递增
                while(!stk.empty() && height[j] <= height[stk.top()]) stk.pop();
                left[j] = stk.empty() ? -1 : stk.top();
                stk.push(j);
            }
            while(!stk.empty()) stk.pop();
            for (int j = n - 1; j >= 0; --j)
            {
                while(!stk.empty() && height[j] <= height[stk.top()]) stk.pop();
                right[j] = stk.empty() ? n : stk.top();
                stk.push(j);
            }
            for (int j = 0; j < n; ++j) ans = max(ans, height[j] * (right[j] - left[j] - 1));
        }
        return ans;
    }
};