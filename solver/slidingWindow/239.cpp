// 第一次做的AC代码
// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         int l = nums.size();

//         deque<int> dq;
//         vector<int> ans;
//         for (int i = 0; i < l; ++i)
//         {
//             if (!dq.empty() && dq.front() == i - k) dq.pop_front();
//             while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
//             dq.push_back(i);
//             if (i >= k - 1) ans.push_back(nums[dq.front()]);
//         }
//         return ans;
//     }
// };

// 旧题温习，力扣特有的困难题比中等题简单一大截（吐槽
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //单调双端队列板子题,从左往右，严格单减
        deque<int> dq;
        vector<int> res;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            if (dq.front() == i - k) dq.pop_front();
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};