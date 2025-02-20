// 用时：14：59
// class Solution {
// public:
//     int calculate(string s) {
//         int len = s.size();
//         char pre = '+';
//         int num = 0;
//         stack<int> stk;
//         for (int i = 0; i < len; ++i)
//         {
//             if (isdigit(s[i])) {num = num * 10 + (s[i] - '0');}
//             else if (s[i] == '(')
//             {
//                 int balance = 1;
//                 int endPos = i + 1;
//                 while(balance)
//                 {
//                     if (s[endPos] == '(') ++balance;
//                     else if (s[endPos] == ')') --balance;
//                     ++endPos;
//                 }
//                 //i为(      endPos - 1为)
//                 num = calculate(s.substr(i + 1, endPos - i - 2));
//                 if (pre == '+') stk.push(num);
//                 else if(pre == '-') stk.push(-num);
//                 else {cout<<"error1! The pre is "<<pre<<'\n';}
//                 while(endPos < len && s[endPos] == ' ') ++endPos;
//                 num = 0;
//                 pre = s[endPos];
//                 i = endPos;
//             }
//             if (s[i] == '+' || s[i] == '-' || i == len - 1)
//             {
//                 if (pre == '+') stk.push(num);
//                 else if (pre == '-') stk.push(-num);
//                 else {cout<<"error2! The pre is "<<pre<<'\n';}
//                 num = 0;
//                 pre = s[i];
//             }
//         }

//         int ans = 0;
//         while(!stk.empty()) {ans += stk.top(); /*cout<<stk.top()<<" ";*/ stk.pop();}
//         return ans;
//     }
// };

//看题解之后做出来的 用时08:15
//用作用域的思想，类似于写解释器的时候把作用域压栈
class Solution {
public:
    int calculate(string s) {
        int len = s.size();
        int ans = 0;
        int num = 0;
        stack<int> globalSigh;
        int curSigh = 1;
        globalSigh.push(1);

        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '+')
            {
                ans += curSigh * num;
                curSigh = globalSigh.top();
                num = 0;
            }
            else if (s[i] == '-')
            {
                ans += curSigh * num;
                curSigh = -globalSigh.top();
                num = 0;
            }
            else if (s[i] == '(') globalSigh.push(curSigh);
            else if (s[i] == ')') globalSigh.pop();
            else if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
        }
        ans += curSigh * num;
        return ans;
    }
};