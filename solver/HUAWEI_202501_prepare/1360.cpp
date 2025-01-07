//看了题解之后写的
class Solution {
private:
    class times{
    public:
        int y, m, d;
        times() {}
        times(const string str)
        {
            y = stoi(str.substr(0, 4));
            m = stoi(str.substr(5, 2));
            d = stoi(str.substr(8, 2));
        }
        times(int y, int m, int d): y(y), m(m), d(d) {}
    };

    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isRun(int y) {return ((y % 400 == 0) || (y % 100 != 0) && (y % 4 == 0));}

    int timesToInt(const times &t)
    {
        int d = t.d, m = t.m, y = t.y;
        int ans = d - 1;
        while(m)
        {
            --m;
            ans += days[m];
            if (m == 2 && isRun(y)) ans += 1;
        }
        ans += 365 * (y - 1971);

        ans += (y - 1) / 4 - 1970 / 4;
        ans -= (y - 1) / 100 - 1970 / 100;
        ans += (y - 1) / 400 - 1970 / 400;
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        times t1(date1);
        times t2(date2);

        return abs(timesToInt(t1) - timesToInt(t2));
    }
};