class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = true, l = nums.size();

        for (int index = 0; index <= l - 2; ++index)
        {
            if (nums[index] <= nums[index + 1]) continue;
            if (!flag) return false;
            flag = false;
            bool f1 = (!index || nums[index - 1] <= nums[index + 1]);
            bool f2 = (index >= l - 2 || nums[index] <= nums[index + 2]);
            if (!f1 && !f2) return false;
            if (f2) nums[index + 1] = nums[index];
        }

        return true;
    }
};