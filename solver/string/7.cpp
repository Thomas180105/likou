class Solution {
public:
    int reverse(int x) {
        int res = 0;
        //通过实验发现，负数取模的结果相当于是相反数取模结果的相反数，所以不需要对于x进行分类讨论

        //力扣上溢出会直接报错，不可以通过res / 10 != copy来那么溢出需要提前探测
        // while(x)
        // {
        //     int copy = res;
        //     res = res * 10 + (x % 10);
        //     if (res / 10 != copy) return 0;
        //     x /= 10;
        // }

        // cout<<0x7fffffff<<'\n';
        //2147483647和-2147483648
        while(x)
        {
            if (res > 214748364 || (res == 214748364 && x % 10 > 7)) return 0;
            if (res < -214748364 || (res == -214748364 && x % 10 < -8)) return 0;
            res = res * 10 + (x % 10);
            x /= 10;
        }

        return res;
    }
};