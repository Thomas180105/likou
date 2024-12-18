//非负整数计算器
class Solution {
public:
    int calculate(string s) {
        vector<int> stk;
        char preSign = '+';
        int num = 0;

        for (int i = 0, s_len = s.size(); i < s_len; ++i)
        {
            if (isdigit(s[i])) num = num * 10 + int(s[i] - '0');
            if ((!isdigit(s[i]) && s[i] != ' ')|| i == s_len - 1)
            {
                switch(preSign)
                {
                    case '+':
                        stk.push_back(num);
                        break;
                    case '-':
                        stk.push_back(-num);
                        break;
                    case '*':
                        stk.back() *= num;
                        break;
                    default:
                        stk.back() /= num;
                        break;
                }

                preSign = s[i];
                num = 0;
            }
        }

        int ans = 0;
        for (auto tmp : stk) ans += tmp;
        return ans;
    }
};