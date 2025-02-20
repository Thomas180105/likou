class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n);
        vector<int> nxt(n);

        prev[0] = nxt[n - 1] = 1;
        for (int i = 1; i < n; ++i) prev[i] = prev[i - 1] * nums[i - 1];
        for (int i = n - 2; i >= 0; --i) nxt[i] = nxt[i + 1] * nums[i + 1];

        vector<int> res;
        for (int i = 0; i < n; ++i) res.push_back(prev[i] * nxt[i]);
        return res;
    }
};