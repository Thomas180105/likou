//第一次AC代码
// class Solution {
// public:
//     string minWindow(string s, string t) {
//         // unordered_map<char, bool> in;//字符是否在t
//         // unordered_map<char, int> times;
//         // unordered_map<char, int> need;
//         // unordered_map<char, bool> enough;

//         // int s_len = s.size(), t_len = t.size();
//         // for (int i = 0; i < t_len; ++i)
//         // {
//         //     in[t[i]] = true;
//         //     enough[t[i]] = false;
//         //     ++need[t[i]];
//         // }

//         // int l = 0, r = -1;
//         // while(++r < s_len)
//         // {
//         //     if (!in[s[r]]) continue;
//         //     ++times[s[r]];
//         //     if (!enough[s[r]] && times[s[r]] >= need[s[r]])
//         //     {
//         //         enough[s[r]] = true;
//         //         bool flag = true;
//         //         for (auto tmp : enough)
//         //         {
//         //             if (!tmp.second) {flag = false; break;}
//         //         }
//         //         if (flag) break;
//         //     }
//         // }
//         // if (r == s_len) return "";

//         // int minL = l, minR = r, minLen = r - l + 1;
//         // while(++l < s_len)
//         // {
//         //     if (!in[s[l - 1]] || --times[s[l - 1]] >= need[s[l - 1]])
//         //     {
//         //         if (r - l + 1 < minLen) {minL = l; minR = r; minLen = r - l + 1;}
//         //         continue;
//         //     }

//         //     while(++r < s_len)
//         //     {
//         //         if (!in[s[r]]) continue;
//         //         ++times[s[r]];
//         //         if (s[r] == s[l - 1])
//         //         {
//         //             if (r - l + 1 < minLen) {minL = l; minR = r; minLen = r - l + 1;}
//         //             break;
//         //         }
//         //     }

//         //     if (r == s_len) break;
//         // }
//         // return s.substr(minL, minLen);
//         vector<int> need(128, 0);
//         vector<bool> in(128, false);

//         int s_len = s.size(), t_len = t.size();
//         int l = 0, r = 0, minL, minLen = s_len + 1, cnt = 0;
//         for (int i = 0; i < t_len; ++i)
//         {
//             in[t[i]] = true;
//             ++need[t[i]];
//         }

//         for (; r < s_len; ++r)
//         {
//             if (in[s[r]])
//             {
//                 if (--need[s[r]] >= 0) ++cnt;

//                 while(cnt == t_len)
//                 {
//                     if (r - l + 1 < minLen) {minLen = r - l + 1; minL = l;}
//                     if (in[s[l]] && ++need[s[l]] > 0) --cnt;
//                     ++l;
//                 }
//             }
//         }

//         return (minLen == s_len + 1) ? "" : s.substr(minL, minLen);
//     }
// };

// 旧题新做
// 其中在if (in[s[l]] && ++need[s[l]] > 0) --cnt;一行中一开始写成了if (++need[s[l]] > 0) --cnt; 导致出错了
class Solution {
public:
    string minWindow(string s, string t) {
        //典型双指针滑动窗口
        int l = 0, r = 0, sLen = s.size(), tLen = t.size();
        int minL, minLen = 1e6;
        //如何统计"涵盖"这一个信息呢？我们可以记录一个vector的信息并使用一个cnt来支持快速判断
        vector<bool> in(256, false);
        vector<int> need(256, 0);
        for (int i = 0; i < tLen; ++i)
        {
            in[t[i]] = true;
            ++need[t[i]];
        }
        int cnt = 0;

        for (; r < sLen; ++r)
        {
            if (in[s[r]])
            {
                if (--need[s[r]] >= 0) ++cnt;//加入r
                //开始维护l
                while(cnt == tLen)
                {
                    if (r - l + 1 < minLen) {minLen = r - l + 1; minL = l;}//统计对于答案的贡献
                    if (in[s[l]] && ++need[s[l]] > 0) --cnt;
                    ++l;
                }
            }
        }

        return minLen == 1e6 ? "" : s.substr(minL, minLen);
    }
};