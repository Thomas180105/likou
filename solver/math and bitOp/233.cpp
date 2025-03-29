class Solution {
public:
    int countDigitOne(int n) {
        //考虑个位(t = 0)上的1，整个的部分就是n/10，最后还有一个前1个，即 n % 10之后在[1, 1]范围内的个数
        //类似地考虑十位(t = 1)上的1，整个的部分就是(n / 100) * 10，然后就是 n % 100之后在[10, 19]范围内的个数
        //百位(t = 2)：(n / 1000) * 100，再加上n % 1000在[100, 199]范围内的个数
        //t = t时，(n / 10^(t + 1)) * 10^t, 以及 n % 10^(t + 1)在[10^t, 2*10^t - 1]内的个数
        int t = 0;
        long long base = 1, res = 0;
        while(true)
        {
            int tmp = 0;
            tmp += (n / (10 * base)) * base;
            if (n % (10 * base) >= base) tmp += min(base, n % (base * 10) - base + 1);
            if (tmp == 0) break;
            res += tmp;
            base *= 10;
        }
        return res;
    }
};
