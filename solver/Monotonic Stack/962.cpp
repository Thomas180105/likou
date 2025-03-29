class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //对于每一个下标考虑其作为j对于答案的贡献，即找到原数组最左边的一个小于等于nums[i]的下标
        //本来第一眼看起来是单调栈那一块的，但是单调栈求解的都是从当前下标往左/往右 第一个满足某一个性质的下标
        //但一细想还是可以用单调栈的思想做，即维护一个可能成为答案的集合
        //第一次来生成关于左端点i的候选者，根据题目，自然是从左往右扫一遍，做一个单减的,要么你下标更小要么你值更小
        //生成完之后考虑每一个点作为右端点对于答案的贡献，从右往左枚举这样的右端点cur。
        //每次首先是要将stk中下标大于cur的pop_back()，然后二分查找，这样是O(NlogN)
        //且慢！既然是返回最长的这样的区间，不用二分查找，直接下面这样
        int len = nums.size();
        vector<int> stk;
        for (int i = 0; i < len; ++i)
        {
            if (stk.empty() || nums[i] < nums[stk.back()]) stk.emplace_back(i);//思路：左端点数值小或者下标小至少占一样，因此维护一个单调减小的单调栈
        }

        int res = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            while(!stk.empty() && nums[i] >= nums[stk.back()])
            {
                res = max(res, i - stk.back());
                stk.pop_back();
            }
            if (stk.empty()) break;//减枝
        }
        return res;
    }
};

