//用时：11：15
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();

        int l = 0, r = len - 1, ans = -1;
        while(l <= r)
        {
            int mid = l + ((r - l) >> 1);

            bool same_before = (mid != 0) && (nums[mid] == nums[mid - 1]);
            bool same_after = (mid < len - 1) && (nums[mid] == nums[mid + 1]);
            if (!same_after && !same_before) {ans = nums[mid]; break;}

            bool target_before = ((mid % 2 == 0) && same_before) || ((mid % 2 == 1) && same_after);
            bool target_after = ((mid % 2 == 0) && same_after) || ((mid % 2 == 1) && same_before);
            if (target_before)
            {
                // cout<<"mid = "<<mid<<", now is target_before";
                r = mid - 1;
            }
            else
            {
                // cout<<"mid = "<<mid<<", now is target_after";
                l = mid + 1;
            }
        }

        return ans;
    }
};