// class Solution {
// private:
//     string nums2str(int num)
//     {
//         if (num == 0) return "0";
//         string res;
//         while(num)
//         {
//             res += static_cast<char>('0' + num % 10);
//             num /= 10;
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
//     static bool cmp(const string &a, const string &b)
//     {
//         int aLen = a.size(), bLen = b.size();
//         int pos = 0;
//         for (int bound = min(aLen, bLen); pos < bound; ++pos)
//         {
//             if (a[pos] != b[pos]) return a[pos] > b[pos];
//         }
//         if (pos == aLen && pos == bLen) return true;
//         if (pos < aLen) return a[pos] != '0';
//         return b[pos] == '0';
//     }
// public:
//     string largestNumber(vector<int>& nums) {
//         //首先是按照每一个小的字符串的首位是第一关键字，然后是第二位，依次递推
//         //如果位数不相等，比如30和3，又比如37和3。前者是需要3 30，后者则是37 3，故而判断一下位数更大的这个数当前位是不是0即可
//         //为了方便这里的处理，将初始给定的数字先转化为字符串比较好,这里记得模拟考试结束之后去查一下相关API而不是自己写实现

//         //位数不相等似乎没有那么容易
//         //比如11131 和1113
//         //11131 1113
//         //1113 11131

//         vector<string> strs;
//         for (auto num : nums) strs.push_back(nums2str(num));
//         sort(strs.begin(), strs.end(), cmp);
//         string res;
//         for (auto tmp : strs) res += tmp;
//         return  res;
//     }
// };

class Solution {
private:
    string nums2str(int num)
    {
        if (num == 0) return "0";
        string res;
        while(num)
        {
            res += static_cast<char>('0' + num % 10);
            num /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    static bool cmp(const string &a, const string &b)
    {
        int aLen = a.size(), bLen = b.size();
        int pos = 0;
        for (int bound = min(aLen, bLen); pos < bound; ++pos)
        {
            if (a[pos] != b[pos]) return a[pos] > b[pos];
        }
        return a + b > b + a;
    }
public:
    string largestNumber(vector<int>& nums) {
        //如果位数不相等，尝试两种拼接方法，然后比较两者哪一个更大即可

        vector<string> strs;
        for (auto num : nums) strs.push_back(nums2str(num));
        sort(strs.begin(), strs.end(), cmp);
        string res;
        for (auto tmp : strs) res += tmp;

        //还需要注意去除前导零,比如[0, 0, 0, 0, 0]会得到“00000”
        return res[0] == '0' ? "0" : res;
    }
};