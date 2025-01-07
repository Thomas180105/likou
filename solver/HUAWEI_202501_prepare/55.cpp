//用时：4:12
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int curPos = 0;
        int right = nums[0];

        while(curPos < len && curPos <= right)
        {
            right = max(right, curPos + nums[curPos]);
            ++curPos;
        }

        return curPos == len;
    }
};