// 自己做完全没思路
// class Solution {
// public:
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         //按照题意是不需要去重的
//         //既然是连续的子数组，第一想法就是滑动窗口，但是怎么work起来需要想想
//         //毕竟这里我们可以很明显地看到对答案产生贡献的区间并不符合一般的滑动窗口的规律，如果维持两个指针不往复的话我们可能需要某些统计策略
//         //p.s. 要是问最长好子数组，那确实就是直接滑动窗口搞定

//         //1 2 1 2 3 为例
//         //r = 0 :
//         //r = 1 : (1 2)
//         //r = 2 : (1 2 1) (2 1)
//         //r = 3 : (1 2 1 2) (2 1 2) (1 2)
//         //r = 4 : (2 3)

//         //r = 0 : (1)
//         //r = 1 : (1 2) ans += 1
//         //r = 2 : (1 2 1) ans += 1
//         //r = 3 : (1 2 1 2) ans += 1
//         //r = 4 : 将要加入的元素会使得数字种类变多，l要开始变动
//         //(1 2 1 2)->(2 1 2)，种类还是不变， ans 理应 += 2
//         //(2 1 2) -> (1 2), 种类不变， ans 理应 += 1
//         //(1 2) -> (2) 现在种类变少，r可以加入新元素 （2 3） ans += 1
//         //综上ans = 7是对的上的，现在问题是要如何统计两个“理应”处对于答案的贡献

//         //（2 2 2 3 1） k = 2
//         // (2 2 2 3) ++
//         // (2 2 2 3) -> (2 2 3)
//         int l = 0, r = 0, len = nums.size(), ans = 0;
//         unordered_map<int, int> hash;
//         for (; r < len; ++r)
//         {
//             ++hash[nums[r]];
//             while()
//         }
//     }
// };

// 想了20分钟不会做。偷看了题解发现可以归约成求解不同整数的个数小于等于k的子数组的个数，至此终于可以很自然地使用滑动窗口力！
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt1 = 0, cnt2 = 0, len = nums.size();
        //以下求解个数小于等于k的子数组的个数
        unordered_map<int, int> hash;
        for (; r < len; ++r)
        {
            ++hash[nums[r]];
            while(l <= r && hash.size() > k)
            {
                if (--hash[nums[l]] == 0) hash.erase(nums[l]);
                ++l;
            }
            if (l <= r) cnt1 += (r - l + 1);
        }

        hash.clear();
        for (l = 0, r = 0; r < len; ++r)
        {
            ++hash[nums[r]];
            while(l <= r && hash.size() > k - 1)
            {
                if (--hash[nums[l]] == 0) hash.erase(nums[l]);
                ++l;
            }
            if (l <= r) cnt2 += (r - l + 1);
        }

        return cnt1 - cnt2;
    }
};