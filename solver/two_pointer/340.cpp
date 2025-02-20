class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int len = s.size();
        int charCnt = 0;
        int pos1 = 0, pos2 = -1, ans = 0;

        unordered_map<char, int> hc;
        while(pos1 < len && pos2 < len)
        {
            if (hc[s[++pos2]]++ == 0) ++charCnt;
            if (pos2 < len && charCnt <= k) ans = max(ans, pos2 - pos1 + 1);
            while(pos1 < len && charCnt > k)
            {
                if (--hc[s[pos1++]] == 0) --charCnt;
            }
        }

        return ans;
    }
};