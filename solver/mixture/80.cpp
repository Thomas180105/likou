class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int pos = 0, ed = 0;//pos是现在在扫描的为止，ed是等待填入的位置
        int cnt = 0;
        for (; pos < len; ++pos)
        {
            if (pos && nums[pos] == nums[pos - 1])
            {
                if (++cnt <= 2) nums[ed++] = nums[pos];
            }
            else
            {
                cnt = 1;
                nums[ed++] = nums[pos];
            }
        }
        return ed;
    }
};