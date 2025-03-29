class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> strs(numRows);
        int sLen = s.size();//每一个下标对应的strs中的下标：pos-> (pos) % (2 * numRows - 2),若结果x< numRows保留x,否则为2 * numRows - 2 - x
        for (int pos = 0; pos < sLen; ++pos)
        {
            int x = pos % (2 * numRows - 2);
            x = (x < numRows ? x : 2 * numRows - 2 - x);
            strs[x] += s[pos];
        }
        string res;
        for (auto str : strs) res += str;
        return res;
    }
};