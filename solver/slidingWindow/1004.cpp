class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, len = nums.size();
        int res = 0, cnt = k;
        for (; r < len; ++r)
        {
            if (nums[r] == 0) --cnt;
            while(cnt < 0)
            {
                if (nums[l] == 0) ++cnt;
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};