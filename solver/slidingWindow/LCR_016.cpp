class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //由于是连续子字符串，直接使用滑动窗口
        int l = 0, r = 0, sLen = s.size();
        unordered_set<char> hash;
        int ans = 0;
        for (; r < sLen; ++r)
        {
            while(hash.find(s[r]) != hash.end()) hash.erase(s[l++]);//加入r
            hash.insert(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};