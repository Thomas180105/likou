class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //第一眼就是n^2logn暴力做，n <= 3000数据范围，略微悬
        //但是这里相当于是给一个target然后要求两数相加等于其，试一下排序加双指针，这样是n^2
        //但是要注意(1)去重(2)三个数下标不可以一样
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ans;
        for (int first = 0; first + 2 < len; ++first)
        {
            if (first && nums[first] == nums[first - 1]) continue;
            int target = -nums[first];
            //接下来找[fisrt + 1, len - 1]范围内找
            int second = first + 1, third = len - 1;
            while(second < third)
            {
                if (second > first + 1 && nums[second] == nums[second - 1]) ++second;//second去重
                else if (nums[second] + nums[third] > target) --third;
                else if (nums[second] + nums[third] < target) ++second;
                else
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                    ++second;
                }
            }
        }
        return ans;
    }
};