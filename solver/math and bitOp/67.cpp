class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        if (a.size() > b.size()) swap(a, b);
        int len1 = a.size(), len2 = b.size();
        int carry = 0, i = 0;
        for (; i < len1; ++i)
        {
            int d1 = a[len1 - 1 - i] - '0', d2 = b[len2 - 1 - i] - '0';
            res += '0' + (d1 + d2 + carry) % 2;
            carry = (d1 + d2 + carry) / 2;
        }

        for (; i < len2; ++i)
        {
            int d2 = b[len2 - 1 - i] - '0';
            res += '0' + (d2 + carry) % 2;
            carry = (d2 + carry) / 2;
        }
        if (carry) res += '1';

        reverse(res.begin(), res.end());
        // cout<<res<<'\n';
        return res;
    }
};