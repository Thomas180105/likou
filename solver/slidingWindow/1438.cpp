//看数据范围最差也要nlogn才能过
//滑动窗口O(N)次滑动，每次滑动需要删除元素、加入元素、查询最大最小值，直接上set好了，这样总共O(NlogN)
//注意是multiset
// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {
//         multiset<int> hst;
//         int l = 0, r = 0, len = nums.size(), ans = 0;
//         for (; r < len; ++r)
//         {
//             hst.insert(nums[r]);
//             while(l <= r && *hst.rbegin() - *hst.begin() > limit) //注意是rbegin()不是end()，这里调试了一会儿
//             {
//                 hst.erase(hst.find(nums[l]));//记得这里erase要传递itr而不是int，不然会全部删除
//                 ++l;
//             }
//             ans = max(ans, r - l + 1);
//         }
//         return ans;
//     }
// };

//看题解发现可以干到O(N)，狠
//由于这里维护的是一个窗口，涉及到删除和加入，查询最大最小值
//可以考虑用单调双端队列
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> queryMax;//单减，查的时候返回front()
        deque<int> queryMin;//单增，查的时候返回front()
        int l = 0, r = 0, len = nums.size(), ans = 0;
        for (; r < len; ++r)
        {
            //插入nums[r]
            while(!queryMax.empty() && nums[r] >= nums[queryMax.back()]) queryMax.pop_back();
            queryMax.push_back(r);
            while(!queryMin.empty() && nums[r] <= nums[queryMin.back()]) queryMin.pop_back();
            queryMin.push_back(r);

            //开始找到满足条件的l
            while(nums[queryMax.front()] - nums[queryMin.front()] > limit)
            {
                if (queryMax.front() == l) queryMax.pop_front();
                if (queryMin.front() == l) queryMin.pop_front();
                ++l;
            }

            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};