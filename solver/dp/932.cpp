// class Solution {
// public:
//     vector<int> beautifulArray(int n) {
//         unordered_map<int, vector<int>> dp;
//         dp[1] = {1};

//         for (int i = 2; i <= (n + 1) / 2; ++i)
//         {
//             vector<int> even = dp[i / 2];
//             vector<int> odd = dp[(i + 1) / 2];
//             vector<int> cur;
//             for (int j = 0; j <= i / 2 - 1; ++j) cur.push_back(2 * even[j]);
//             for (int j = 0; j <= (i + 1) / 2 - 1; ++j) cur.push_back(2 * odd[j] - 1);
//             dp[i] = cur;
//         }

//         vector<int> ans;
//         for (int j = 0; j <= n / 2 - 1; ++j) ans.push_back(2 * dp[n / 2][j]);
//         for (int j = 0; j <= (n + 1) / 2 - 1; ++j) ans.push_back(2 * dp[(n + 1) / 2][j] - 1);
//         return ans;
//     }
// };

class Solution {
private:
    unordered_map<int, vector<int>> memory;

    const vector<int> & search(int n)
    {
        if (memory.count(n)) return memory[n];
        vector<int> even = search(n / 2);
        vector<int> odd = search((n + 1) / 2);
        vector<int> res;

        res.reserve(n);
        for (int i = 0; i < n / 2; ++i) res.push_back(2 * even[i]);
        for (int i = 0; i < (n + 1) / 2; ++i) res.push_back(2 * odd[i] - 1);

        memory[n] = res;
        return memory[n];
    }
public:
    vector<int> beautifulArray(int n) {
        memory[1] = {1};
        return search(n);
    }
};