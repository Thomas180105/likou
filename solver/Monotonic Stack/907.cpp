//注意一个是第一个小于，一个是第一个小于等于，这样才不会计算重复
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        //暴力是N^2肯定超了，那直接考虑到单调的方向
        //对于每个元素arr[i]，考虑从它开始向左边数，大于等于它的元素个数left[i];从它开始向右边数，大于它的元素个数right[i]
        //即左边第一个小于它的数，右边第一个小于等于它的数
        stack<int> stk;
        int len = arr.size();
        vector<int> left(len);
        vector<int> right(len);

        //从左往右，单调增的栈，入栈时元素更新left
        for (int i = 0; i < len; ++i)
        {
            while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();
            left[i] = i - (stk.empty() ? -1 : stk.top());
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        //从右往左，同样是单增
        for (int i = len - 1; i >= 0; --i)
        {
            while(!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();
            right[i] = (stk.empty() ? len : stk.top()) - i;
            stk.push(i);
        }

        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < len; ++i) ans = (ans + static_cast<long long>(arr[i]) * right[i] * left[i]) % mod;
        return ans;
    }
};