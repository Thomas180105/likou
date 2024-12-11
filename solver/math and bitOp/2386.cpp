struct cmp{
    bool operator()(const pair<long long, int> &a, const pair<long long, int> &b)
    {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b. second;
    }
};
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long tot = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] >= 0) tot += nums[i];
            else nums[i] = -nums[i];
        }

        sort(nums.begin(), nums.end());

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, cmp> que;
        que.push({0, 0});//(i， j)和为i,且以nums[j - 1]结尾的子序列

        while(--k)
        {
            auto [subSum, index] = que.top();
            // cout<<subSum<<" "<<index<<'\n';
            que.pop();

            if (index < n)
            {
                que.push({subSum + nums[index], index + 1});
                if (index) que.push({subSum + nums[index] - nums[index - 1], index + 1});
            }
        }
        return tot - que.top().first;
    }
};