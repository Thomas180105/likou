class Solution {
public:
    int calculate(string s) {
        char preOp = '+';
        stack<int> stk;
        for (int i = 0, len = s.size(); i < len; ++i)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                int num = s[i] - '0';
                while(i + 1 < len && (s[i + 1] == ' ' || (s[i + 1] >= '0' && s[i + 1] <= '9')))
                {
                    ++i;
                    if (s[i] == ' ') continue;
                    num = num * 10 +(s[i] - '0');
                }
                // cout<<"now the num is "<<num<<" preOp is"<<preOp<<'\n'; 
                if (preOp == '+') stk.push(num);
                else if (preOp == '-') stk.push(-num);
                else if (preOp == '*') {stk.top() *= num;}
                else stk.top() /= num;
            }
            else if (s[i] != ' ') preOp = s[i];
        }

        int res = 0;
        while(!stk.empty()) {/*cout<<stk.top()<<" ";*/ res += stk.top(); stk.pop();}
        return res;
    }
};