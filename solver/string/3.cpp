// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_set<char> hash;
//         int ans = 0, l = 0, r = -1, len = s.size();
//         while(++r < len)
//         {
//             while(r < len && !hash.count(s[r])) hash.insert(s[r++]);
//             ans = max(r - l, ans);
//             while(r < len && s[l] != s[r]) hash.erase(s[l++]);
//             ++l;
//         }
//         return ans;
//     }
// };

//下面这个滑动窗口的写法更加不容易出错，以后一律用这个范式
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int len = s.size(),ans = 0;
        for (int l = 0, r = 0; r < len; ++r)
        {
            while(l <= r && hash.count(s[r])) hash.erase(s[l++]);//找到第一个符合当前r的l
            hash.insert(s[r]);//当前r正式生效，维护数据结构
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

