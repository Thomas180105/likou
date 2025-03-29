class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int sign = 1;
        int pos = 0, sLen = s.size();
        long long upperBound = 0x7fffffff;
        long long lowerBound = -upperBound-1;

        while(pos < sLen && s[pos] == ' ') ++pos;

        if (pos < sLen && s[pos] == '+') ++pos;
        else if (pos < sLen && s[pos] == '-') {sign = -1; ++pos;}

        cout<<"now sign = "<<sign<<", pos = "<<pos<<'\n';
        while(pos < sLen && isdigit(s[pos]))
        {
            ans = ans * 10 + (s[pos] - '0');
            ans = sign == 1 ? min(ans, upperBound) : min(ans, -lowerBound);
            ++pos;
        }

        return sign * ans;
    }
};