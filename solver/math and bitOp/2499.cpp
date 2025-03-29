class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        //纯纯智商题，想了30分钟完全没想法，看了题解之后实现的（甚至看灵神写的题解一开始还没看懂）
        long long ans = 0;
        int swapCnt = 0, mostNum, mostCnt = 0, n = nums1.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i)
        {
            if (nums1[i] == nums2[i])
            {
                ++swapCnt;
                ans += i;
                if (++freq[nums1[i]] > mostCnt) {mostCnt = freq[nums1[i]]; mostNum = nums1[i];}
            }
        }

        //此处分类讨论
        //1. swapCnt >= 2 * mostCnt，则ans即为上述统计下标和。
        //证明思路:由于相同的下标处是一定要发生交换的，因此ans >= 上述统计下标和。下面分类讨论说明存在一种交换方式使得ans = 上述统计下标和
        //1.1 若swapCnt为偶数，那么内部交换既可，这里证明思路类似于摩尔投票正确性证明
        //1.2 若swapCnt为奇数，注意到此时freq中至少有三种数字，那么其中必然有一种是可以和num1[0]交换（这里要再分类讨论一下细节，即num1[0] == num2[0] 与 num1[0] != nums2[0]两种情况，具体略。灵神题解这里没有讨论但其实要讨论才能说明正确性），然后剩下的swapCnt - 1同1.1
        //2. swapCnt < 2 * mostCnt， 则由抽屉原理，不存在可行交换方案， ans = -1

        for (int i = 0; i < n && swapCnt < 2 * mostCnt; ++i)//去找可以与mostCnt抗衡的数对
        {
            if (nums1[i] != nums2[i] && nums1[i] != mostNum && nums2[i] != mostNum)
            {
                ans += i;
                ++swapCnt;
            }
        }

        return swapCnt < 2 * mostCnt ? -1 : ans;
    }
};