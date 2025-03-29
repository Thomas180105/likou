class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //首先n方枚举起点和终点
        //然后n双指针找另外两个
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int st = 0; st + 4 <= len; ++st)
        {
            if (st && nums[st] == nums[st - 1]) continue;
            for (int ed = len - 1; ed >= st + 3; --ed)
            {
                if (ed != len - 1 && nums[ed] == nums[ed + 1]) continue;
                long long sum = static_cast<long long>(target) - nums[st] - nums[ed];//时刻注意溢出风险
                int first = st + 1, second = ed - 1;
                while(first < second)//两者相加需要等于sum，如果加入答案时保证了first的不重复，就可以保证second的不重复
                {
                    if (nums[first] + nums[second] < sum) ++first;
                    else if (nums[first] + nums[second] > sum) --second;
                    else if (first != st + 1 && nums[first] == nums[first - 1]) ++first;
                    else res.push_back({nums[st], nums[first++], nums[second], nums[ed]});
                }
            }
        }

        return res;
    }
};