// 第一次AC时的代码
// class Solution {
// private:
//     bool isSame(unordered_map<char, int> &curHash, unordered_map<char, int> &targetHash)
//     {
//         for (char key = 'a'; key <= 'z'; ++key) if (curHash[key] != targetHash[key]) return false; //会导致插入一些(, 0)
//         return true;
//     }
// public:
//     vector<int> findAnagrams(string s, string p) {
//         int s_len = s.size();
//         int p_len = p.size();

//         if (s_len < p_len) return {};

//         unordered_map<char, int> curHash;
//         unordered_map<char, int> targetHash;
//         vector<int> res;

//         for (int i = 0; i < p_len; ++i)
//         {
//             ++curHash[s[i]];
//             ++targetHash[p[i]];
//         }

//         if (isSame(curHash, targetHash)) res.push_back(0);
//         //s_len - 1 - x + 1 = p_len   x = p_le
//         for (int i = 1; i <= s_len - p_len; ++i)
//         {
//             --curHash[s[i - 1]];
//             ++curHash[s[i + p_len - 1]];
//             if (isSame(curHash, targetHash)) res.push_back(i);
//         }

//         return res;
//     }
// };

// 旧题新做
// 用hash.empty()来表征之前做法中两个数组是否相同，这样检查的开销从O(pLen)下降为O(1)，当然也可以开两个vec，然后维护一个int的值diff来记录，同样也可以O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> hash;
        int sLen = s.size(), pLen = p.size();
        if (pLen > sLen) return {};

        for (int i = 0; i < pLen; ++i) ++hash[p[i]];
        for (int i = 0; i < pLen; ++i) if (--hash[s[i]] == 0) hash.erase(s[i]);
        if (hash.empty()) res.push_back(0);
        for (int l = 1; l <= sLen - pLen; ++l)
        {
            //删除l - 1,加上l + pLen - 1
            if (++hash[s[l - 1]] == 0) hash.erase(s[l - 1]);
            if (--hash[s[l + pLen - 1]] == 0) hash.erase(s[l + pLen - 1]);

            if (hash.empty()) res.push_back(l);
        }
        return res;
    }
};