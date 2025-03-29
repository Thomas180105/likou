class Solution {
public:
    int smallestFactorization(int num) {
        //首先因式分解，如果有不是2,3,5,7的因子直接return 0
        //然后开始贪心，因为结果x是最小正整数，所以位数要尽可能小
        //2 2 2 ->8 这一个肯定是最优先
        //2 2 -> 4
        //2 3 -> 6
        //3 3 ->9

        //（1）0个2和若干个3 无讨论必要
        //（2）1个2和x个3  3内部配优先，理由如下
        //（2.1）当x为奇数时，2和3配，然后3内部配
        //（2.2）当x为偶数时，2 3 3 -> 6 3 或者 2 9，显然是3内部配更好
        //（3）2个2和x个3  类似（2）中探索，显然应该是先3内部配，然后再考虑2和3

        //综上，先2 2 2 ->8，然后3 3 ->9，然后2 3 -> 6，最后2 2 -> 4

        if (num == 1) return 1;
        vector<int> cnt(10, 0);
        vector<int> factorSet = {2, 3, 5, 7};
        for (auto factor : factorSet)
        {
            for (; num % factor == 0; num /= factor) ++cnt[factor];
        }
        if (num != 1) return 0;
        long long x = 0;
        int bound = 0x7fffffff;
        cnt[8] = cnt[2] / 3;
        cnt[2] %= 3;
        cnt[9] = cnt[3] / 2;
        cnt[3] %= 2;
        cnt[6] = min(cnt[2], cnt[3]);
        cnt[2] -= cnt[6];
        cnt[3] -= cnt[6];
        cnt[4] = cnt[2] / 2;
        cnt[2] %= 2;
        vector<int> tmpSet = {2, 3, 4, 5, 6, 7, 8, 9};

        for (auto cur : tmpSet)
        {
            for (int i = 0; i < cnt[cur]; ++i)
            {
                x = x * 10 + cur;
                if (x > bound) return 0;
            }
        }
        return x;
    }
};