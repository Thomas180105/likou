//初始用时14min8s，写的一个奇丑无比但是不太容易出错的递归代码
// class Solution {
// public:
//     string decodeString(string s) {
//         ///想法：（1）递归找每一个[对应的]，然后无脑写一个递归
//         //如果写迭代的话，考虑使用栈，不过目前没有想到怎么写
//         string res;
//         int len = s.size(), pos = 0;
//         while(pos < len)
//         {
//             if (!isdigit(s[pos])) res += s[pos++];
//             else
//             {
//                 int preTime = 0, left = pos;
//                 for (; isdigit(s[left]); ++left) preTime = preTime * 10 + (s[left] - '0');
//                 int right = left + 1, balance = 1;
//                 while(balance)//默认输入是合法的，括号闭合
//                 {
//                     if (s[right] == '[') ++balance;
//                     if (s[right] == ']') --balance;
//                     ++right;
//                 }
//                 --right;//left 为[ right 为]
//                 string subRes = decodeString(s.substr(left + 1, right - left - 1));
//                 for (int i = 0; i < preTime; ++i) res += subRes;
//                 pos = right + 1;
//             }
//         }
//         return res;
//     }
// };

//看了题解之后，写的一版框架感更好的递归
//在看过一次题解之后自己写仍然花了11min，这种写法谨慎使用，原因有二
//（1）写的时候需要注意getStr()返回条件，过程中需要注意对于pos的合理更新，比如两次跳过括号
//（2）这种写法函数调用次数较多，开销比较大
// class Solution {
// private:
//     //方便起见将str和pos放在类成员变量这里，也可以不这样而是所有getNum和getStr引用传参
//     string str;
//     int pos;
//     int sLen;

//     int getNum()
//     {
//         int res = 0;
//         while(pos < sLen && isdigit(str[pos])) res = res * 10 + (str[pos++] - '0');
//         return res;
//     }
//     string getStr()
//     {
//         //这种递归的写法一定要注意出口，即返回条件
//         if (pos == sLen || str[pos] == ']') return "";

//         string res;
//         if (isdigit(str[pos]))
//         {
//             int repTime = getNum();
//             ++pos;//跳过[
//             string subRes = getStr();//遇到对应于当前的'['的']'会返回
//             ++pos;//跳过]
//             for (int i = 0; i < repTime; ++i) res += subRes;
//         }
//         else if (str[pos] >= 'a' && str[pos] <= 'z') res = string(1, str[pos++]);

//         return res + getStr();
//     }
// public:
//     string decodeString(string s) {
//         sLen = s.size();
//         str = s;
//         pos = 0;
//         return getStr();
//     }
// };

//看了题解之后写的一版迭代，对于这种写法很不熟悉，两天以及一周后重新写一遍
class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> countStack;
        std::stack<std::string> stringStack;
        std::string currentString = "";
        int k = 0;

        for (char ch : s)
        {
            if (isdigit(ch)) k = k * 10 + (ch - '0');
            else if (ch == '[')
            {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            }
            else if (ch == ']')
            {
                string temp = stringStack.top();
                stringStack.pop();
                int repeatTimes = countStack.top();
                countStack.pop();
                for (int i = 0; i < repeatTimes; i++) temp += currentString;
                currentString = temp;
            }
            else currentString += ch;
        }

        return currentString;
    }
};