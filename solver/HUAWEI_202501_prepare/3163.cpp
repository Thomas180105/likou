// 用时 6:03
class Solution {
public:
    string compressedString(string word) {
        string res;
        char curCh = 0;
        int cnt = 0;
        for (auto tmp: word)
        {
            if (tmp == curCh)
            {
                ++cnt;
                if (cnt == 9) {res += '0' + cnt; res += curCh; curCh = 0;}
            }
            else
            {
                if (curCh) {res += char('0' + cnt); res += curCh;}
                curCh = tmp;
                cnt = 1;
            }
        }
        if (curCh) {res += '0' + cnt; res += curCh;}
        return res;
    }
};