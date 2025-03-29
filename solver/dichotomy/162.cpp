class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //如果nums[0] > nums[1] 或者nums[len - 1] > nums[len - 2]就可以直接return
        //否则，往中间去找，此时有一个不变量就是两端元素都是“局部比较小”的
        //每次检查mid，首先mid有可能就是答案
        //如果mid不是，说明mid左右两端至少有一个比mid大
        //如果nums[mid + 1] > nums[mid]就往右边搜索，否则往左边搜（相当于保持不变量）
        int l = 0, r = nums.size() - 1, len = nums.size();
        if (len == 1) return 0;

        if (nums[len - 1] > nums[len - 2]) return len - 1;
        if (nums[0] > nums[1]) return 0;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            // cout<<"now l = "<<l<<", r = "<<r<<", mid = "<<mid<<'\n';
            if ((mid == 0 || nums[mid] > nums[mid - 1]) && (mid == len - 1 || nums[mid] > nums[mid + 1])) return mid;
            else if ((mid < len - 1 && nums[mid + 1] > nums[mid])) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};