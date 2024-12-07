class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int l = 1, r = x;
        while(l < r)
        {
            int mid = l + ((r - l + 1) >> 1);
            if (static_cast<long long>(mid) * mid > x) r = mid - 1;
            else l = mid;
        }
        return l;
    }
};