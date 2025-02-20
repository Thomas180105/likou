class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //考虑每一个index处的高度，看以这个高度往两边能延申的最大宽度，相乘即可以对答案产生贡献。
        //暴力做的话上面想法是O(N^2)，可以考虑使用单调栈维护信息，这样是O(N)
        //向右延申：从index一个个往右，直到最后一个大于等于height[index]的下标。
        //自然想到从左往右扫，维护一个(不严格)单调递增的单调栈，当元素被pop出单调栈的时候上述往右延申的信息就可以被维护了
        int len = heights.size();
        vector<int> rightIndex(len);
        vector<int> leftIndex(len);
        stack<int> stk;
        for (int i = 0; i < len; ++i)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {rightIndex[stk.top()] = i - 1; stk.pop();}
            stk.push(i);
        }
        while(!stk.empty()) {rightIndex[stk.top()] = len - 1; stk.pop();}
        // for (int i = 0; i < len; ++i) cout<<rightIndex[i]<<" ";cout<<'\n';
        for (int i = len - 1; i >= 0; --i)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i]) {leftIndex[stk.top()] = i + 1; stk.pop();}
            stk.push(i);
        }
        while(!stk.empty()) {leftIndex[stk.top()] = 0; stk.pop();}

        int ans = 0;
        for (int i = 0; i < len; ++i) ans = max(ans, heights[i] * (rightIndex[i] - leftIndex[i] + 1));
        return ans;
    }
};