class Solution {
public:
    double myPow(double x, int _n) {
        long long n = _n;
        if (n < 0) {x = 1 / x; n = -n;}
        if (n == 0) return 1;

        double base = x;
        long long remain = n;
        double ans = 1;
        while(remain)
        {
            if (remain & 1) ans *= base;
            base *= base;
            remain >>= 1;
        }
        return ans;
    }
};