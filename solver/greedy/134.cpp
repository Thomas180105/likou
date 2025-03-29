class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //我的理解是，需要找一个下标，使得从这个下标开始计算的前缀和中，对于任意位置的前缀和均有preSumGet >= preSumCost
        //那其实这里可以简化一下，直接将get-cost得到一个新的数组，然后对这个新的数组从某一个下标开始求前缀和，要求处处前缀和非负
        //范围是1e5，考虑O(N)或者O(NlogN)的算法
        //手玩一下
        //gas = [1,2,3,4,5], cost = [3,4,5,1,2] -> [-2, -2, -2, 3, 3]
        //那其实感觉可以指针扫一遍即可
        int n = gas.size();
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = gas[i] - cost[i];
        int st = 0, sum = 0;
        for (int pos = 0; pos < n; ++pos)
        {
            sum += nums[pos];
            if (sum < 0)
            {
                st = pos + 1;
                sum = 0;
            }
        }
        //由于从st到数组最后面，整个扫描过程和处处非负，且按照贪心的过程st的下标足够小，这说明从st开始已经是最优解，下面验证可行性即可
        for (int pos = 0; pos < st; ++pos)
        {
            sum += nums[pos];
            if (sum < 0) return -1;
        }
        return st;
    }
};