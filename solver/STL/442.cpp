class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //仅使用常量额外空间，所以不能用哈希
        //观察到题目中关键条件”所有整数都在范围[1, n]内“
        //任何求和、位运算原则上完全不可行，因为这里最终是需要返回一个数组，从信息论的角度感受到完全不可行

        //完全不会做，放弃，看题解好了
        //震惊到了
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            while(nums[nums[i] - 1] != nums[i]) swap(nums[nums[i] - 1], nums[i]);
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) if (nums[i] != i + 1) ans.push_back(nums[i]);
        return ans;
    }
};