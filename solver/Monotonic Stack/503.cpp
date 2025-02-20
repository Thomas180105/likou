class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<pair<int, int>> que;//单调栈 (index, value)
        vector<int> ans(nums.size());

        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            while(!que.empty() && nums[i] > que.back().second)
            {
                ans[que.back().first] = nums[i];
                que.pop_back();
            }
            que.push_back({i, nums[i]});
        }

        if (que.empty()) return ans;
        for (int i = 0, bound = que[0].first; i < bound; ++i)
        {
            if (que.empty()) break;
            while(!que.empty() && nums[i] > que.back().second)
            {
                ans[que.back().first] = nums[i];1
                que.pop_back();
            }
        }

        while(!que.empty() && que.front().second != que.back().second)
        {
            ans[que.back().first] = que.front().second;
            que.pop_back();
        }

        while(!que.empty())
        {
            ans[que.back().first] = -1;
            que.pop_back();
        }

        return ans;
    }
};