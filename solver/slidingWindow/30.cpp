class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        //划分方式有word[0].size()这么多种，每次划分用s.size()这么久的时间扫一遍
        if (words.empty()) return {};
        int sLen = s.size(), wLen = words[0].size(), wordCnt = words.size();
        if (sLen < wLen * wordCnt) return {};

        vector<int> res;
        for (int startPos = 0; startPos < wLen && startPos <= sLen - wLen * wordCnt; ++startPos)
        {
            unordered_map<string, int> hash;
            for (int i = 0; i < wordCnt; ++i) ++hash[words[i]];
            for (int i = 0; i < wordCnt; ++i)
            {
                string curS = s.substr(startPos + i * wLen, wLen);
                if (--hash[curS] == 0) hash.erase(curS);
            }
            if (hash.empty()) res.push_back(startPos);

            for (int subStart = startPos + wLen; subStart <= sLen - wLen * wordCnt; subStart += wLen)
            {
                //减去startPos的，
                if (++hash[s.substr(subStart - wLen, wLen)] == 0) hash.erase(s.substr(subStart - wLen, wLen));
                if (--hash[s.substr(subStart + (wordCnt - 1) * wLen, wLen)] == 0) hash.erase(s.substr(subStart + (wordCnt - 1) * wLen, wLen));
                if (hash.empty()) res.push_back(subStart);
            }
        }

        return res;
    }
};