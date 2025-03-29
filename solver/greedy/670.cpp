class Solution {
public:
    int maximumSwap(int num) {
        if (num == 0) return 0;
        //从首位开始看后续有没有更大的数，如果有，就交换当前这个数字dig1;否则返回本身
        //第二个候选就是dig2后面的数字中最大的数字，如果有重复的，则返回最靠后的
        vector<int> digits;
        int copyNum = num;
        while(copyNum)
        {
            digits.push_back(copyNum % 10);
            copyNum /= 10;
        }
        reverse(digits.begin(), digits.end());

        int maxDig = -1, len = digits.size();
        vector<bool> flag(len, false);
        for (int pos = len - 1; pos >= 0; --pos)
        {
            if (maxDig > digits[pos]) flag[pos] = true;
            else maxDig = digits[pos];
        }
        int stPos = 0;
        for (; stPos < len; ++stPos) if (flag[stPos]) break;
        if (stPos == len) return num;

        int bigNum = -1, edPos = -1;
        for (int i = stPos + 1; i < len; ++i)
        {
            if (digits[i] == bigNum) edPos = i;
            else if (digits[i] > bigNum)
            {
                bigNum = digits[i];
                edPos = i;
            }
        }
        swap(digits[stPos], digits[edPos]);
        int ans = 0;
        for (int i = 0; i < len; ++i) ans = ans * 10 + digits[i];
        return ans;
    }
};