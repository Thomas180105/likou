class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // vector<int> bit(32, 0);
        // for (const auto &tmp : nums)
        // {
        //     int cur = tmp, index = 0;
        //     while(cur)
        //     {
        //         bit[index++] += cur & 1;
        //         cur = cur >> 1;
        //     }
        // }

        // uint32_t ans = 0, base = 1;
        // for (int i = 0; i < 32; ++i)
        // {
        //     if(bit[i] % 3) ans += base;
        //     base *= 2;
        // }
        // return ans;
        int ans = 0;
        for (int i = 0; i < 32; ++i)
        {
            int tot = 0;
            for(auto tmp : nums)
            {
                if ((tmp >> i) & 1) ++tot;
            }

            if (tot % 3) ans |= (1 << i);
        }

        return ans;
    }
};