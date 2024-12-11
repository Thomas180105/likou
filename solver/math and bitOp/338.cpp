class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        // for (int i = 0; i <= n; ++i)
        // {
        //     int cnt = 0, cur = i;
        //     while(cur) {cur -= cur & (-cur); ++cnt;}
        //     res[i] = cnt;
        // }

        for (int i = 1; i <= n; ++i)
        {
            res[i] = (i & 1) ? res[i - 1] + 1 : res[i>>1];
        }

        return res;
    }
};