class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int res = 1e5;

        while(l <= r)
        {
            int mid = l + ((r - l) >> 1);
            res = min(res, nums[mid]);
            if (nums[mid] == nums[l]) ++l;
            else
            {
                if (nums[mid] <= nums[r])//右半是有序的
                {
                    r = mid - 1;
                }
                else
                {
                    res = min(res, nums[l]);
                    l = mid + 1;
                }
            }
        }

        return res;
    }
};