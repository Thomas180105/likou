class Solution {
public:
    string minWindow(string s, string t) {
        // unordered_map<char, bool> in;//字符是否在t
        // unordered_map<char, int> times;
        // unordered_map<char, int> need;
        // unordered_map<char, bool> enough;

        // int s_len = s.size(), t_len = t.size();
        // for (int i = 0; i < t_len; ++i)
        // {
        //     in[t[i]] = true;
        //     enough[t[i]] = false;
        //     ++need[t[i]];
        // }

        // int l = 0, r = -1;
        // while(++r < s_len)
        // {
        //     if (!in[s[r]]) continue;
        //     ++times[s[r]];
        //     if (!enough[s[r]] && times[s[r]] >= need[s[r]])
        //     {
        //         enough[s[r]] = true;
        //         bool flag = true;
        //         for (auto tmp : enough)
        //         {
        //             if (!tmp.second) {flag = false; break;}
        //         }
        //         if (flag) break;
        //     }
        // }
        // if (r == s_len) return "";

        // int minL = l, minR = r, minLen = r - l + 1;
        // while(++l < s_len)
        // {
        //     if (!in[s[l - 1]] || --times[s[l - 1]] >= need[s[l - 1]])
        //     {
        //         if (r - l + 1 < minLen) {minL = l; minR = r; minLen = r - l + 1;}
        //         continue;
        //     }

        //     while(++r < s_len)
        //     {
        //         if (!in[s[r]]) continue;
        //         ++times[s[r]];
        //         if (s[r] == s[l - 1])
        //         {
        //             if (r - l + 1 < minLen) {minL = l; minR = r; minLen = r - l + 1;}
        //             break;
        //         }
        //     }

        //     if (r == s_len) break;
        // }
        // return s.substr(minL, minLen);
        vector<int> need(128, 0);
        vector<bool> in(128, false);

        int s_len = s.size(), t_len = t.size();
        int l = 0, r = 0, minL, minLen = s_len + 1, cnt = 0;
        for (int i = 0; i < t_len; ++i)
        {
            in[t[i]] = true;
            ++need[t[i]];
        }

        for (; r < s_len; ++r)
        {
            if (in[s[r]])
            {
                if (--need[s[r]] >= 0) ++cnt;

                while(cnt == t_len)
                {
                    if (r - l + 1 < minLen) {minLen = r - l + 1; minL = l;}
                    if (in[s[l]] && ++need[s[l]] > 0) --cnt;
                    ++l;
                }
            }
        }

        return (minLen == s_len + 1) ? "" : s.substr(minL, minLen);
    }
};