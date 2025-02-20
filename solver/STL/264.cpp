class Solution {
public:
    int nthUglyNumber(int n) {
        // set<long long> que;
        // vector<int> primes = {2, 3, 5};
        // long long uppperBound = 1;
        // uppperBound <<= 32;

        // que.insert(1);

        // while(--n)
        // {
        //     long long cur = *que.begin();
        //     que.erase(que.begin());
        //     for (auto p : primes) if (cur * p < uppperBound) que.insert(cur * p);
        // }

        // return *que.begin();
        // priority_queue<long long, vector<long long>, greater<long long>> que;
        // unordered_set<long long> hash;

        // que.push(1), hash.insert(1);
        // vector<int> primes = {2, 3, 5};

        // while(--n)
        // {
        //     auto cur = que.top();
        //     que.pop();

        //     for (auto p : primes)
        //     {
        //         if (!hash.count(p * cur))
        //         {
        //             hash.insert(p * cur);
        //             que.push(p * cur);
        //         }
        //     }
        // }
        // return que.top();

        vector<int> primes = {2, 3, 5};
        vector<int> pos = {1, 1, 1};
        int p_cnt = 3;
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = min(dp[pos[0]] * primes[0], min(dp[pos[1]] * primes[1], dp[pos[2]] * primes[2]));
            for (int j = 0; j < p_cnt; ++j) if (dp[i] == dp[pos[j]] * primes[j]) ++pos[j];
        }
        return dp[n];
    }
};