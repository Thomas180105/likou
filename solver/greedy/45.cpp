class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int curEnd = 0, nextEnd = -1, pos = 0, ans = 0;
        while(pos < len - 1 && pos <= curEnd)
        {
            nextEnd = max(nextEnd, pos + nums[pos]);
            if (pos == curEnd)
            {
                ++ans;
                curEnd = nextEnd;
            }
            ++pos;
        }
        return ans;
    }
};