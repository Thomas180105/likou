class Solution {
private:
    void dfs(vector<string> &res, string curStr, string s, int pos, vector<string>& wordDict)
    {
        if (pos == s.size()) {res.push_back(curStr); return;}

        for (int i = 0, len = wordDict.size(); i < len; ++i)
        {
            if (pos + wordDict[i].size() - 1 >= s.size()) continue;
            if (s.substr(pos, wordDict[i].size()) == wordDict[i])
            {
                string append = pos == 0 ? wordDict[i] : " " + wordDict[i];
                dfs(res, curStr + append, s, pos + wordDict[i].size(), wordDict);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        dfs(res, "", s, 0, wordDict);
        return res;
    }
};