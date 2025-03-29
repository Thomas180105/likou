class Solution {
private:
    int solver(vector<int>& nums, int l, int r) // [l, mid] [mid + 1, r]
    {
        int cnt = 0;
        //递归出口
        if (l >= r) return 0;

        //向下递归
        int mid = l + (r - l) / 2;
        cnt += solver(nums, l, mid); //统计了左半内部的贡献，同时左半数组有序
        cnt += solver(nums, mid + 1, r); //统计了右半内部的贡献，同时右半数组有序

        // 现在统计交叉贡献 1 2 3 8      1 2 3 4  
        int pos1 = mid, pos2 = r;
        while(pos1 >= l && pos2 >= mid + 1)
        {
            while(pos2 >= mid + 1 && nums[pos1] <= static_cast<long long>(2) * nums[pos2]) --pos2;
            if (pos2 >= mid + 1) cnt += (pos2 - mid);
            --pos1;
        }
        //合并成一个更大的有序数组
        vector<int> tmp(r - l + 1);
        pos1 = l, pos2 = mid + 1;
        int p = 0;
        while(pos1 <= mid && pos2 <= r)
        {
            if (nums[pos1] <= nums[pos2]) tmp[p++] = nums[pos1++];
            else tmp[p++] = nums[pos2++];
        }
        while(pos1 <= mid) tmp[p++] = nums[pos1++];
        while(pos2 <= r) tmp[p++] = nums[pos2++];
        for (int i = l; i <= r; ++i) nums[i] = tmp[i - l];

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        //我们可以考分治法
        //考虑两个有序的数组，前者的下标都小于后者的下标，那么这样我们可以直接双指针线性扫一遍，然后再归并两个有序数组
        //T(N) = 2 * T(N / 2) + O(N), 这样T(N) = O(NlogN)，试一试！
        return solver(nums, 0, nums.size() - 1);
    }
};