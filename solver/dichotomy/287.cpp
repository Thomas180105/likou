class Solution {
public:
     int findDuplicate(vector<int>& nums) {
         int n = nums.size() - 1;
         int l = 1, r = n, ans;
         while(l <= r)
         {
             int mid = l + (r - l) / 2, cnt = 0;
             for (auto tmp : nums) cnt += (tmp <= mid);
             if (cnt <= mid) l = mid + 1;
             else
             {
                 ans = mid;
                 r = mid - 1;
             }
         }
         return ans;
     }
    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size() - 1;
    //     int l = 1, r = n, ans;
    //     while(l < r)
    //     {
    //         int mid = l + (r - l) / 2, cnt = 0;
    //         for (auto tmp : nums) cnt += (tmp <= mid);
    //         if (cnt <= mid) l = mid + 1;
    //         else r = mid;
    //     }
    //     return l;
    // }

    // int findDuplicate(vector<int>& nums) {
    //     int n = nums.size() - 1;
    //     int bit_max;
    //     for (int i = 31; i >= 0; --i) if ((n >> i) & 1) {bit_max = i; break;}

    //     int ans = 0;
    //     cout<<"here\n";
    //     for (int bit = 0; bit <= bit_max; ++bit)
    //     {
    //         int cnt1 = 0, cnt2 = 0;
    //         for (int i = 0; i <= n; ++i) if ((nums[i] >> bit) & 1) ++cnt1;
    //         for (int i = 1; i <= n; ++i) if ((i >> bit) & 1) ++cnt2;
    //         if (cnt1 > cnt2) ans |= (1 << bit);
    //     }
    //     return ans;
    // }

    // 图的顶点是[0, n]，图的边是i->nums[i]
    // 从0开始，一直沿着边往下一个顶点走，显然这个过程可以无限进行下去无穷无尽所以一定有环
    // 为什么入环点前一个位置一定是重复的数： 很简单，因为有两个位置指向了入环点。
//    int findDuplicate(vector<int>& nums) {
//        int slow = 0, fast = 0;
//        do {
//            slow = nums[slow];
//            fast = nums[nums[fast]];
//        } while(slow != fast);
//        slow = 0;
//        while(slow != fast)
//        {
//            slow = nums[slow];
//            fast = nums[fast];
//        }
//        return slow;
    }
};