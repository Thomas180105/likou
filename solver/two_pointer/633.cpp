class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = sqrt(c) + 1;

        while(l <= r)
        {
            if (l * l + r * r == c) return true;
            else if (l * l + r * r < c) ++l;
            else --r;
        }

        return false;
    }
};