class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> times;
        int l = nums.size();
        for (int i = 0; i < l; ++i) ++times[nums[i]];

        vector<vector<int>> vec;
        for (auto tmp : times)
        {
            vec.push_back({tmp.first, tmp.second}); //(num, time)
        }
        sort(vec.begin(), vec.end(), cmp);

        vector<int> ans;
        for (int i = 0; i < k; ++i)
        {
            ans.push_back(vec[i][0]);
        }
        return ans;
    }

    static bool cmp(const vector<int> &a, const vector<int> &b)
    {
        return a[1] > b[1];
    }
};