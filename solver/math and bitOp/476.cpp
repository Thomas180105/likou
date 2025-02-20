class Solution {
public:
    int findComplement(int num) {
        // int base = 1, mask = 0;
        // for (int i = 0; i < 31; ++i)
        // {
        //     mask += base;
        //     if (mask >= num) break;
        //     base <<= 1;
        // }
        // return ~num & mask;

        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return ~num &mask;
    }
};