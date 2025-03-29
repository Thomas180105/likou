class Solution {
public:
    string removeKdigits(string num, int k) {
        //一眼看起来就是贪心加单调栈？
        //样例提示不可以有任何前导零

        //先手玩一下
        //119 k = 1 ->去掉9
        //191 k = 1 ->去掉9
        //911 k = 1 ->去掉9

        //1859 k = 1 ->去掉8 得到159
        //1859 k = 2 ->去掉8 9 得到15

        //贪心，即优先处理较高位置上的数字，去掉一个数更优更当且仅当这个数字后面为空或者后面的数字小于其(如果等于的话，我们暂时不丢弃当前数字，正确性待思考)
        //如果次数没有用完就从尾巴开始继续去掉
        int len = num.size();
        vector<int> stk;
        for (int pos = 0; pos < len; ++pos)
        {
            while (k && !stk.empty() && stk.back() > num[pos] - '0') {--k; stk.pop_back();}
            stk.push_back(num[pos] - '0');
        }

        while(k--) stk.pop_back();

        // int ans = 0;
        // for (auto t : stk) ans = ans * 10 + t;
        // return to_string(ans);

        string ans;
        bool zeroFlag = true;
        for (auto t : stk)
        {
            if (zeroFlag && t == 0) continue;
            zeroFlag = false;
            ans += static_cast<char>('0' + t);
        }
        return ans == "" ? "0" : ans;
    }
};