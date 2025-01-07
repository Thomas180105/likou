// 用时 2:38
class Solution {
public:
    int uniquePaths(int m, int n) {
        --m, --n;
        long long res = 1;
        for(int i = 1; i <= n; ++i) res = res * (m + i) / i;
        return res;
    }
};