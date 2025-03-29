class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            if (nums[mid] < nums[r])//至少右边是有序的
            {
                if (nums[mid] <= target && target <= nums[r]) l = mid + 1;
                else r = mid - 1;
            }
            else//至少左边是有序的
            {
                if (nums[l] <= target && target <= nums[mid]) r = mid - 1;
                else l = mid + 1;
            }
        }
        return -1;
    }
};