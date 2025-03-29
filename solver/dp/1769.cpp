class Solution {
public:
    vector<int> minOperations(string boxes) {
        //暴力模拟O(N^2)，数据范围2e3可过
        //考虑直接线性扫两边即可
        int n = boxes.size();
        vector<int> front(n, 0);//front[i]:将下标i前面的所有小球移动到i所需要的所有花费
        vector<int> back(n, 0);//back[i]

        int frontCnt = boxes[0] == '1';
        for (int i = 1; i < n; ++i)
        {
            front[i] = front[i - 1] + frontCnt;
            frontCnt += boxes[i] == '1';
        }

        int backCnt = boxes[n - 1] == '1';
        for (int i = n - 2; i >= 0; --i)
        {
            back[i] = back[i + 1] + backCnt;
            backCnt += boxes[i] == '1';
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) ans[i] = front[i] + back[i];
        return ans;
    }
};