class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hc;
        for (auto ch : s) ++hc[ch];

        vector<pair<char, int>> vec;
        for (auto it : hc) vec.emplace_back(it);

        sort(vec.begin(), vec.end(), [](const pair<char, int> &a, const pair<char, int> &b) -> bool {return a.second > b.second;});

        string res;
        for (auto [cur, num] : vec)
        {
            for (int i = 0; i < num; ++i) res.push_back(cur);
        }

        return res;
    }
};