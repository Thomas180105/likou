class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto str : strs)
        {
            string before = str;
            sort(str.begin(), str.end());
            hash[str].emplace_back(before);
        }

        vector<vector<string>> ans;
        for (auto [key, vec] : hash) ans.emplace_back(vec);
        return ans;
    }
};