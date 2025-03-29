class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        //前几天刚做一堆关于单调栈的题，所以这题直接看出来可以做N次最大柱形图的那道题目，即O(N^2)。
        //如果要dp的话，看起来需要dp[i][j][k]:(i,j)为右下角，宽度为k的矩形的最大高度，这样是O(N^3)的状态，每次转移是O(1)，总共是O(N^3)，劣于原有方案

        int m = matrix.size(), n = matrix.empty() ? 0 : matrix[0].size();
        if (!m || !n) return 0;
        vector<int> height(n, 0);
        int res = 0;
        for (int row = 0; row < m; ++row)
        {
            for (int j = 0; j < n; ++j) height[j] = matrix[row][j] == '0' ? 0 : height[j] + 1;//第一次被坑了，注意审题是'0'不是0
            // cout<<"now the row is "<<row<<'\n';
            // cout<<"the height is ";
            // for (int j = 0; j < n; ++j) cout<<height[j]<<" ";cout<<'\n';
            vector<int> left(n), right(n);//第一个
            stack<int> stk;
            for (int j = 0; j < n; ++j)
            {
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

            for (int j = 0; j < n; ++j) res = max(res, height[j] * (right[j] - left[j] - 1));
        }
        return res;
    }
};