class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //考虑拆分为两个问题比较好处理
        //首先求找出三个整数，使得其大于等于target并且尽可能接近
        //然后再找小于target那一侧的
        //每个问题直接使用双指针来做，O(N^2)

        sort(nums.begin(), nums.end());
        int n = nums.size();

        int sum1 = 1e5;
        for (int st = 0; st < n; ++st)
        {
            int l = st + 1, r = n - 1;
            while(l < r)
            {
                int tmp = nums[st] + nums[l] + nums[r];
                if (tmp < target) ++l;
                else
                {
                    if (sum1 - target > tmp - target) sum1 = tmp;
                    --r;
                }
            }
        }

        if (sum1 == target) return target;

        int sum2 = -1e5;
        for (int st = 0; st < n; ++st)
        {
            int l = st + 1, r = n - 1;
            while(l < r)
            {
                int tmp = nums[st] + nums[l] + nums[r];
                if (tmp >= target) --r;
                else
                {
                    if (target - sum2 > target - tmp) sum2 = tmp;
                    ++l;
                }
            }
        }

        return sum1 - target <= target - sum2 ? sum1 : sum2;
    }
};