class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> res;
        char curCh = 0;
        int cnt = 0;
        for (auto ch : chars)
        {
            if (ch != curCh)
            {
                if (curCh != 0)
                {
                    //处理
                    res.push_back(curCh);
                    if (cnt != 1)
                    {
                        string numStr = to_string(cnt);
                        for (auto numCh : numStr) res.push_back(numCh);
                    }
                }

                curCh = ch;
                cnt = 1;
            }
            else ++cnt;
        }
        res.push_back(curCh);
        if (cnt != 1)
        {
            string numStr = to_string(cnt);
            for (auto numCh : numStr) res.push_back(numCh);
        }

        chars = res;
        return chars.size();
    }
};