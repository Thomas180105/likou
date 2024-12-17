class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hash;

        int ans = 0;
        for (const auto& cur : nums)
        {
            auto pos = hash.find(cur);
            if (pos != hash.end()) continue;

            auto posL = hash.find(cur - 1);
            auto posR = hash.find(cur + 1);

            int cntL = (posL == hash.end() ? 0 : posL->second);
            int cntR = (posR == hash.end() ? 0 : posR->second);
            int curLen = cntL + cntR + 1;
            ans = max(ans, curLen);

            hash[cur] = hash[cur - cntL] = hash[cur + cntR] = curLen;//保证两端的信息被正确维护，hash[cur]只是单纯声明此数字已经见过
        }

        return ans;
    }
};