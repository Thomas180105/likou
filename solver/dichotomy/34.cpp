class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        //第一次出现：找第一个大于等于这个数
        while(l < r)
        {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }
        if (l == nums.size() || nums[l] != target) return {-1, -1};
        vector<int> ans({l});

        l = 0, r = nums.size() - 1;
        //最后一次出现，找小于等于这个数的值
        while(l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (nums[mid] > target) r = mid - 1;
            else l = mid;
        }
        ans.push_back(l);
        return ans;
    }
};