// 傻逼了，这里不满足单调性，不可以用二分来做
// class Solution {
// private:
//     bool isValid(const string &s, int len)
//     {
//         for (int i = 0; i < len / 2; ++i) if (s[i] != s[len - 1 - i]) return false;
//         return true;
//     }
// public:
//     string shortestPalindrome(string s) {
//         //看数据范围至少要做到nlogn
//         //题目相当于是求最长的s的前缀长度，使得该前缀是回文串，那直接写一个对于长度的二分试一试
//         int l = 1, r = s.size(), ans, sLen = s.size();
//         while(l <= r)
//         {
//             int mid = l + (r - l) / 2;
//             if (isValid(s, mid)) {ans = mid; l = mid + 1;}
//             else {r = mid - 1;}
//         }
//         cout<<"the ans is "<<ans<<'\n';
//         string res;
//         for (int i = 0, bound = sLen - ans; i < bound; ++i) res += s[sLen - 1 - i];
//         res += s;
//         return res;
//     }
// };

class Solution {
public:
    string shortestPalindrome(string s) {
        //题目相当于是求最长的s的前缀长度，使得该前缀是回文串，那直接写一个nlogn的对于长度的二分。傻逼了，这里不满足单调性，不可以用二分来做
        //花费了7分钟试错，现在快速调整思路，既然要求的是最长的s的前缀长度，使得该前缀是回文串。需要找一个比暴力N方更好的做法
        //可不可以用dp来实现线性时间内求得目标呢
        //或者用滑动窗口/双指针？显然不对，在确定一个窗口内部是不是回文串还是需要O(N)，这和暴力没区别
        //回到动态规划的思路上，想要线性时间找到所求，那么状态数就是O(N)个，并且需要O(1)转移才行，想不出来
        //已知的动态规划的字符串算法中中KMP是线性的，看看是不是可以用？他那个求的是最长匹配真前后缀
        //想了20分钟不会做，看题解

        //方法一：字符串哈希！忘记这个也是线性的了。常见的线性做法别只会滑动窗口和双指针了，字符串场景下记得枚举字符串哈希。前几天还刷了字符串哈希的题目，操
        // int sLen = s.size();
        // long long base = 101, mod = 1e9 + 7, high = 1, ans;
        // long long num1 = 0, num2 = 0;
        // for (int i = 0; i < sLen; ++i)
        // {
        //     num1 = (num1 * base + s[i]) % mod;//正向
        //     num2 = (num2 + s[i] * high) % mod;//反向
        //     high = (high * base) % mod;
        //     if (num1 == num2) ans = i + 1;
        // }
        // string res;
        // for (int i = 0, bound = sLen - ans; i < bound; ++i) res += s[sLen - 1 - i];
        // res += s;
        // return res;
        //方法二：就是KMP匹配啊你个傻子，aabc -> aabc#cbaa然后KMP求next就行了！
        if (s.empty()) return s;
        int sLen = s.size();
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());
        string new_s = s + "#" + reversed_s;

        vector<int> next(new_s.size(), 0);
        for (int i = 1; i < new_s.size(); ++i)
        {
            int j = next[i - 1];
            while (j > 0 && new_s[i] != new_s[j]) j = next[j - 1];
            if (new_s[i] == new_s[j]) j++;
            next[i] = j;
        }
        string res;
        for (int i = 0, bound = sLen - next.back(); i < bound; ++i) res += s[sLen - 1 - i];
        res += s;
        return res;
    }
};