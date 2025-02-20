class Solution {
private:
    void reverseStr(string &str)
    {
        int len = str.size();
        for (int i = 0, bound = len / 2; i < bound; ++i) swap(str[i], str[len - 1 - i]);
    }
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber)
        {
            res += ((--columnNumber) % 26) + 'A';
            columnNumber /= 26;
        }
        reverseStr(res);
        return res;
    }
};