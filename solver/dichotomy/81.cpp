class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r)//注意这里不可以写成<，否则结果错误
        {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] == target) return true;
            if (nums[mid] == nums[l]) ++l;
            else
            {
                if (nums[mid] <= nums[r])//右半是有序的
                {
                    if (target > nums[mid] && target <= nums[r]) l = mid + 1;
                    else r = mid - 1;
                }
                else //左半是有序的
                {
                    if (target < nums[mid] && target >= nums[l]) r = mid - 1;
                    else l = mid + 1;
                }
            }
        }
        return false;
    }
};