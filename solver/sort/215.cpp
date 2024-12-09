class Solution {
private:
    int quickFind(vector<int> & nums, int start, int end, int k)//左闭右闭
    {
        if (start == end) return nums[start];
        int pos1 = start, pos2 = end;

        int key = nums[start];
        while(start < end)
        {
            while(end > start && nums[end] >= key) --end;
            nums[start] = nums[end];
            while(start < end && nums[start] <= key) ++start;
            nums[end] = nums[start];
        }
        nums[start] = key;

        if (pos2 - end >= k) return quickFind(nums, end + 1, pos2, k);
        return quickFind(nums, pos1, end, k - (pos2 - end));
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickFind(nums, 0, nums.size() - 1, k);
    }
};