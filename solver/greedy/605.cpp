class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        int ans = 0, index = 0, curLen = 0;
        for(; index < l; ++index)
        {
            if (flowerbed[index] == 1)
            {
                if (curLen) {ans += (--curLen + 1) / 2;}
                curLen = -1;
            }
            else ++curLen;
        }
        if (curLen > 0) ans += (curLen + 1) / 2;
        return ans >= n;
    }
};