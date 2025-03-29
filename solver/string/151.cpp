class Solution {
public:
    string reverseWords(string s) {
        vector<string> strs;
        string cur;

        int pos = 0, sLen = s.size();
        while(pos < sLen)
        {
            while(pos < sLen && s[pos] == ' ') ++pos;
            while(pos < sLen && s[pos] != ' ') cur += s[pos++];
            if (!cur.empty()) strs.push_back(cur);//尾随空格
            cur = "";
        }

        string res;
        for (int i = strs.size() - 1; i >= 0; --i)
        {
            res += strs[i];
            if (i) res += ' ';
        }
        return res;
    }
};