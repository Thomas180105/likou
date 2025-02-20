class Solution {
private:
    static bool cmp(const string &str1, const string &str2)
    {
        if (str1.size() != str2.size()) return str1.size() > str2.size();
        return str1 < str2;
    }

    bool isSubStr(const string &s, const string &d)
    {
        int pos1 = 0, pos2 = 0;
        int len1 = s.size(), len2 = d.size();
        while(pos1 < len1 && pos2 < len2)
        {
            if (s[pos1] == d[pos2]) ++pos1, ++pos2;
            else ++pos1;
        }

        return pos2 == len2;
    }
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), cmp);

        for (auto tmp : dictionary)
        {
            if (isSubStr(s, tmp)) return tmp;
        }

        return "";
    }
};