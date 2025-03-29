// class Solution {
// private:
//     int len;
//     unordered_set<int> hash;
//     bool isValid(int l, int r)
//     {
//         if (l < 0 || l >= len || r < 0 || r >= len || hash.count(l * len + r)) return false;
//         hash.insert(l * len + r);
//         return true;
//     }
//     struct cmp{
//         bool operator()(const vector<int> &a, const vector<int> &b)
//         {
//             return a[0] > b[0];
//         }
//     };
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         //用堆来存储候选者，这样初始堆里面n个数，后续最多到n+k个数，时间复杂度是nlogn + klog(n + k)
//         len = nums.size();
//         hash.clear();

//         sort(nums.begin(), nums.end());
//         priority_queue<vector<int>, vector<vector<int>>, cmp> que;
//         for (int i = 0; i + 1 < len; ++i) que.push({nums[i + 1] - nums[i], i, i + 1});

//         while(--k)
//         {
//             auto cur = que.top();
//             que.pop();
//             int l = cur[1], r = cur[2];
//             if (isValid(l - 1, r)) que.push({nums[r] - nums[l - 1], l - 1, r});
//             if (isValid(l, r + 1)) que.push({nums[r + 1] - nums[l], l, r + 1});
//         }
//         return que.top()[0];
//     }
// };

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        //用堆来存储候选者，这样初始堆里面n个数，后续最多到n+k个数，时间复杂度是nlogn + klog(n + k)
        //交了一发，超时了，因为k可以很大，到1e8这个量级，所以上面这个时间复杂度炸了

        //考虑对于答案进行二分
        sort(nums.begin(), nums.end());
        int len = nums.size(), l = 0, r = nums.back() - nums[0];

        while(l < r)
        {
            int mid = l + (r - l) / 2, cnt = 0;
            for (int i = 0; i < len; ++i) cnt += (i - (lower_bound(nums.begin(), nums.begin() + i, nums[i] - mid) - nums.begin()));
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};