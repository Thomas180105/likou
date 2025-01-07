//用时 11::13
class Solution {
private:
    bool isSame(unordered_map<char, int> &curHash, unordered_map<char, int> &targetHash)
    {
        for (char key = 'a'; key <= 'z'; ++key) if (curHash[key] != targetHash[key]) return false; //会导致插入一些(, 0)
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();

        if (s_len < p_len) return {};

        unordered_map<char, int> curHash;
        unordered_map<char, int> targetHash;
        vector<int> res;

        for (int i = 0; i < p_len; ++i)
        {
            ++curHash[s[i]];
            ++targetHash[p[i]];
        }

        if (isSame(curHash, targetHash)) res.push_back(0);
        //s_len - 1 - x + 1 = p_len   x = p_le
        for (int i = 1; i <= s_len - p_len; ++i)
        {
            --curHash[s[i - 1]];
            ++curHash[s[i + p_len - 1]];
            if (isSame(curHash, targetHash)) res.push_back(i);
        }

        return res;
    }
};