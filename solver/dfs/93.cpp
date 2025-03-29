// 下面是写了45分钟还是WA的一个模拟考试时的最终代码
// class Solution {
// private:
//     //cnt：在处理第几个段，curStr：现在处理得到的字符串，pos：在s中的下标， curNum：目前这段的数字
//     void dfs(vector<string> &ans, int cnt, string &curStr, const string &s, int pos, int curNum)
//     {
//         if (cnt == 4)
//         {
//             if (pos == s.size())
//             {
//                 curStr.pop_back();//把最后一个多余的'.'去掉
//                 ans.push_back(curStr);
//             }
//             return;
//         }

//         //选择一：把当前分段，pos不变； 要求：不可以划分空段
//         if (curNum != -1)
//         {
//             curStr += '.';
//             dfs(ans, cnt + 1, curStr, s, pos, -1);
//             curStr.pop_back();
//         }

//         //debug的时候发现会出现curStr为255.255.11.135,pos = s.size()但cnt = 3的情况
//         //所以下面这个判断应该要移动到选择一之后而不是选择一之前
//         if (pos == s.size()) return;

//         //选择二：不分新段，加入当前数字，pos++；要求：没有前导零、数字大小合法
//         if (curNum != 0)
//         {
//             if (curNum == -1) curNum = 0;//初始化一下
//             curNum = curNum * 10 + (s[pos] - '0');
//             if (curNum <= 255)
//             {
//                 curStr.push_back(s[pos]);
//                 dfs(ans, cnt, curStr, s, pos + 1, curNum);
//                 curStr.pop_back();
//             }
//         }
//     }
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> ans;
//         string cur;
//         dfs(ans, 0, cur, s, 0, -1);
//         return ans;
//     }
// };

下面是写了对上面代码的修正，可AC
class Solution {
private:
    //cnt：在处理第几个段，curStr：现在处理得到的字符串，pos：在s中的下标， curNum：目前这段的数字
    void dfs(vector<string> &ans, int cnt, string &curStr, const string &s, int pos, int curNum)
    {
        if (cnt == 4)
        {
            if (pos == s.size())
            {
                curStr.pop_back();//把最后一个多余的'.'去掉
                ans.push_back(curStr);
                //[bug 2 已修复] 之前的代码多了一个pop_back，从而使得一路回溯的时候最后一个pop_back()会作用于一个空字符串而报错
                //（1）教训一：切记，要回溯的话对于引用的修改一定要检查是不是成双成对
                //（2）教训二：程序运行时报错：Line 253: Char 22: runtime error: addition of unsigned offset to 0x7f9ebc4001b0 overflowed to 0x7f9ebc4001af (basic_string.h) SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/lib/gcc/x86_64-linux-gnu/14/../../../../include/c++/14/bits/basic_string.h:262:22
                //     当时看到一直以为是s访问越界之类的，找了半天都没有找到，说明对于这一类报错并不熟悉
                curStr.push_back('.');
            }
            return;
        }

        //选择一：把当前分段，pos不变； 要求：不可以划分空段
        if (curNum != -1)
        {
            curStr += '.';
            dfs(ans, cnt + 1, curStr, s, pos, -1);
            curStr.pop_back();
        }

        //debug的时候发现会出现curStr为255.255.11.135,pos = s.size()但cnt = 3的情况
        //所以下面这个判断应该要移动到选择一之后而不是选择一之前
        if (pos == s.size()) return;

        //选择二：不分新段，加入当前数字，pos++；要求：没有前导零、数字大小合法
        if (curNum != 0)
        {
            if (curNum == -1) curNum = 0;//初始化一下
            curNum = curNum * 10 + (s[pos] - '0');
            if (curNum <= 255)
            {
                curStr.push_back(s[pos]);
                dfs(ans, cnt, curStr, s, pos + 1, curNum);
                curStr.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string cur;
        dfs(ans, 0, cur, s, 0, -1);
        return ans;
    }
};

//按照题解来写的一版，与我自己逐位置dfs来说，这样写函数调用次数更少，同时debug难度低很多
//知道自己写的代码哪里错了之后，也要学习一下题解这里的dfs思路，粒度可以更大
// class Solution {
// private:
//     void dfs(vector<string>& ans, const string& s, int start, int part, string path) {
//         if (part == 4)
//         {
//             if (start == s.size())
//             {
//                 path.pop_back();
//                 ans.push_back(path);
//             }
//             return;
//         }
//         for (int len = 1; len <= 3; ++len)
//         {
//             if (start + len > s.size()) break;
//             string num = s.substr(start, len);
//             if (num.size() > 1 && num[0] == '0') break;
//             if (stoi(num) > 255) break;
//             dfs(ans, s, start + len, part + 1, path + num + ".");
//         }
//     }
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> ans;
//         if (s.size() < 4 || s.size() > 12) return ans;
//         dfs(ans, s, 0, 0, "");
//         return ans;
//     }
// };

//下面这个把path用引用来存，而在函数体内部用string来存copy的实现，空间占用还是一样，所以要省空间只能是传引用且函数体内部不用string来存copy
// class Solution {
// private:
//     void dfs(vector<string>& ans, const string& s, int start, int part, string &path) {
//         if (part == 4)
//         {
//             if (start == s.size()) ans.push_back(path.substr(0, path.size() - 1));
//             return;
//         }

//         for (int len = 1; len <= 3; ++len)
//         {
//             if (start + len > s.size()) break;
//             string num = s.substr(start, len);
//             if (num.size() > 1 && num[0] == '0') break;
//             if (stoi(num) > 255) break;
//             string copy = path;
//             path = path + num + ".";
//             dfs(ans, s, start + len, part + 1, path);
//             path = copy;
//         }
//     }
// public:
//     vector<string> restoreIpAddresses(string s) {
//         vector<string> ans;
//         if (s.size() < 4 || s.size() > 12) return ans;
//         string path;
//         dfs(ans, s, 0, 0, path);
//         return ans;
//     }
// };