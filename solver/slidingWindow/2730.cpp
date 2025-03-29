class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        //第一眼看起来像是dp，但是感觉dp存储的信息并不是太够？
        //“最长”，且要求的是连续区间，考虑滑动窗口

        int sLen = s.size(), l = 0, r = 0;
        int ans = 0;

        int cnt = 0;//还没有出现过一对相邻字符是相等的
        for (; r < sLen; ++r)
        {
            //加入r
            if (r && s[r] == s[r - 1]) ++cnt;
            //维护l
            if (cnt >= 2)
            {
                while(s[l] != s[l + 1]) ++l;
                ++l;
                --cnt;
            }
            //统计答案
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};