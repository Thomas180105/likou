class Solution {
public:
    int calculate(string s) {
        int s_len = s.size();
        int num = 0;
        stack<int> stk;
        char pre = '+';
        for (int i = 0; i < s_len; ++i)
        {
            if (isdigit(s[i])) num = num * 10 + (s[i] - '0');
            if (s[i] == '(')
            {
                int j = i + 1;
                int balance = 1;
                while(j < s_len && balance)
                {
                    if (s[j] == '(') ++balance;
                    if (s[j] == ')') --balance;
                    ++j;
                }
                --j;

                int result = calculate(s.substr(i + 1, j - i - 1));

                if (pre == '+') stk.push(result);
                else if (pre == '-') stk.push(-result);
                else if (pre == '*') stk.top() *= result;
                else stk.top() /= result;

                do{
                    ++j;
                } while(j < s_len && s[j] == ' ');
                pre = s[j];
                num = 0;
                i = j;
            }
            else if (i == s_len - 1 || (!isdigit(s[i]) && s[i] != ' '))
            {
                if (pre == '+') stk.push(num);
                else if (pre == '-') stk.push(-num);
                else if (pre == '*') stk.top() *= num;
                else if (pre == '/') stk.top() /= num;
                else {cout<<"error! pre = "<<pre<<'\n';}
                pre = s[i];
                num = 0;
            }
        }

        int ans = 0;
        while(!stk.empty()) {ans += stk.top(); stk.pop();}
        return ans;
    }
};