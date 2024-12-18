class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int l = nums.size();
        vector<int> preSum(l + 1, 0);
        for (int i = 1; i <= l; ++i) preSum[i] = preSum[i - 1] + nums[i - 1];

        unordered_map<int, int> info;
        int ans = 0;
        info[0] = 1;
        for (int i = 1; i <= l; ++i)//由于子序列需要非空，所以不从0开始
        {
            if (info.count(preSum[i] - k)) {ans += info[preSum[i] - k]; /*cout<<"i = "<<i<<" "<<"adder = "<<info[preSum[i] - k]<<"\n";*/}
            ++info[preSum[i]];
        }
        return ans;
    }
};