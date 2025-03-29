// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         //实现非负大整数相乘，长度在200以内，这个数据范围直接上模拟就行，完全不用FFT
//         if (num1 == "0" || num2 == "0") return "0";//代替结果前导零特判

//         int len1 = num1.size(), len2 = num2.size();
//         vector<string> nums(len2);

//         //先将num2[i]与num1相乘的结果存储到nums[i]中，注意此时末尾没有填写i个零
//         for (int i = 0; i < len2; ++i)
//         {
//             string tmp;
//             int carry = 0;
//             for (int j = 0; j < len1; ++j)
//             {
//                 int multiply = carry + (num2[i] - '0') * (num1[j] - '0');
//                 tmp += static_cast<char>(multiply % 10 + '0');
//                 carry = multiply / 10;
//             }
//             if (carry) tmp += static_cast<char>(carry + '0');
//             // reverse(tmp.begin(), tmp.end());
//             //e.g. "12" * "2" -> "42"
//             nums.push_back(tmp);
//             cout<<"nums["<<i<<"] = "<<nums[i]<<'\n';
//         }

//         string res;//现在需要将len2个字符串加起来，首先最终结果的第i位（第0位为最低位）是由nums[k][i - k]参与贡献的
//         //9999 * 9999 < 10^4 * 10^4 - 1, 两者相乘结果字符串的长度一定是小于等于len1 + len2的
//         int carry = 0;
//         for (int i = 0, bound = len1 + len2; i < bound; ++i)
//         {
//             //nums[k][i - k]贡献给第i位，其中 0 <= k < len2 && 0 <= i - k < nums[k].size()
//             //即0 <= k <= min(len2 - 1, i) ,同时i < k + nums[k].size()
//             int tmpSum = 0;
//             for (int k = 0; k <= min(len2 - 1, i); ++k)
//             {
//                 if (i - k < nums[k].size()) tmpSum += (nums[k][i - k] - '0');
//             }
//             tmpSum += carry;
//             res += static_cast<char>(tmpSum / 10 + '0');
//             carry = tmpSum / 10;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int len1 = num1.size(), len2 = num2.size();
        vector<string> nums(len2);

        for (int i = 0; i < len2; ++i)
        {
            string tmp;
            int carry = 0;
            for (int j = 0; j < len1; ++j)
            {
                int multiply = carry + (num2[i] - '0') * (num1[j] - '0');
                tmp += static_cast<char>(multiply % 10 + '0');
                carry = multiply / 10;
            }
            if (carry) tmp += static_cast<char>(carry + '0');
            nums[i] = tmp;
        }

        string res;
        int carry = 0;
        for (int i = 0, bound = len1 + len2; i < bound; ++i)
        {
            int tmpSum = carry;
            for (int k = 0; k <= min(len2 - 1, i); ++k)
            {
                if (i - k < nums[k].size()) tmpSum += (nums[k][i - k] - '0');
            }
            res += static_cast<char>(tmpSum % 10 + '0');
            carry = tmpSum / 10;
        }

        if (carry) res += static_cast<char>(carry + '0');

        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};