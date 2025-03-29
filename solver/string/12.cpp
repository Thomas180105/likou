class Solution {
public:
    string intToRoman(int num) {
        string res(num / 1000, 'M'); //千位小于等于3，先直接处理
        num %= 1000;

        //接下来考虑百位
        if (num / 100)
        {
            int cnt = num / 100;
            num %= 100;
            if (cnt == 4) res += "CD";
            else if (cnt == 9) res += "CM";
            else if (cnt < 4) res += string(cnt, 'C');
            else res += ("D" + string(cnt - 5, 'C'));
        }

        //十位
        if (num / 10)
        {
            int cnt = num / 10;
            num %= 10;
            if (cnt == 4) res += "XL";
            else if (cnt == 9) res += "XC";
            else if (cnt < 4) res += string(cnt, 'X');
            else res += ("L" + string(cnt - 5, 'X'));
        }

        //个位
        if (num)
        {
            if (num == 4) res += "IV";
            else if (num == 9) res += "IX";
            else if (num < 4) res += string(num, 'I');
            else res += ("V" + string(num - 5, 'I'));
        }

        return res;
    }
};