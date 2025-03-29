class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        //不需要用multiset
        set<int> hst;
        for (int i = 0, n = nums.size(); i < n; ++i)
        {
            auto itr = hst.lower_bound(nums[i] - valueDiff);
            if (itr != hst.end() && *itr <= nums[i] + valueDiff) return true;
            hst.insert(nums[i]);
            if (i >= indexDiff) hst.erase(nums[i - indexDiff]);
        }
        return false;
    }
};