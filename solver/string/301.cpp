//下面这种做法编码花费55分钟，通过案例110/129
// class Solution {
// private:
//     void addToAns(const vector<set<string>> sets, vector<string> &ans, int pos, string str)
//     {
//         if (pos == sets.size()) {ans.push_back(str); return;}
//         for (auto slice : sets[pos]) addToAns(sets, ans, pos + 1, str + slice);
//     }
//     void modifyRight(string s, set<string> &curSet)
//     {
//         int pos = 0, l = 0, r = 0, sLen = s.size();
//         while(pos < sLen)
//         {
//             if (s[pos] == '(') ++l;
//             if (s[pos] == ')') ++r;
//             if (s[pos] == ')')
//             {
//                 string tmp;
//                 for (int i = 0; i < sLen; ++i) if (i != pos) tmp += s[i];
//                 curSet.insert(tmp);
//             }
//             ++pos;
//         }
//     }
//     void modifyLeft(string s, int pos, int l, int r, int k, set<string> &curSet)
//     {
//         if (pos == s.size())
//         {
//             if (k == 0) curSet.insert(s);
//             return;
//         }

//         if (s[pos] == '(') ++l;
//         if (s[pos] == ')') ++r;
//         if (r > l) return;
//         //选择继续往下
//         modifyLeft(s, pos + 1, l, r, k, curSet);
//         //选择删除当前左括号并往下
//         if (k > 0 && l > r && s[pos] == '(')
//         {
//             string tmp;
//             for (int i = 0, len = s.size(); i < len; ++i) if (i != pos) tmp += s[i];
//             modifyLeft(tmp, pos , l - 1, r, k - 1, curSet);//注意这里pos不需要+1
//         }
//     }
// public:
//     vector<string> removeInvalidParentheses(string s) {
//         //一串括号合法，当且仅当从左往右进行遍历的时候，左括号数量时刻大于等于右括号数量，且最终相等
//         //不妨考虑做一个左括号数量前缀和以及右括号数量前缀和，删除括号相当于被删除index一直到末尾的区间修改
//         //()())()
//         //left: 1 1 2 2 2 3 3
//         //right:0 1 1 2 3 3 4
//         //每次一出现right > left的错误，立即修正，修正方式为删除任意一个右括号,但是需要去重
//         //修正完成之后，得到set1{"()()", "(())"}, 剩下的字符串是"()"
//         //遍历到结尾，没出现问题，于是set2{"()"}，将所有set每个依次选一个便得到了最终答案
//         //如果出现了问题，即left != right，记left = right + k,那么需要修正k次，每次修正方式为删除left > right处的左括号。并且注意前面的选择会导致后面可选位点的变化,所以写成dfs
//         //上述这种一遇到错误区间就进行右括号删除的做法花费55分钟实现并调试之后通过案例110/129
//         //错误样例")()))())))"、
//         //调试输出信息如下
//         // a modifyRight called for subStr: )
//         // the modifyRight return with set:
//         // a modifyRight called for subStr: ())
//         // the modifyRight return with set:()
//         // a modifyRight called for subStr: )
//         // the modifyRight return with set:
//         // a modifyRight called for subStr: ())
//         // the modifyRight return with set:()
//         // a modifyRight called for subStr: )
//         // the modifyRight return with set:
//         // a modifyRight called for subStr: )
//         // the modifyRight return with set:
//         //输出：["()()"]， 预期输出["(())","()()"]
//         //这说明上述流程存在硬伤，如果是机考时遇到也可以拿部分分，但是想要AC的话需要思路上改变



//         vector<set<string>> sets;
//         int pos = 0, sLen = s.size(), l = 0, r = 0, st = 0;
//         while(pos < sLen)
//         {
//             if (s[pos] == '(') ++l;
//             if (s[pos] == ')') ++r;
//             if (l < r)
//             {
//                 set<string> set;
//                 cout<<"a modifyRight called for subStr: "<<s.substr(st, pos + 1 - st)<<'\n';
//                 modifyRight(s.substr(st, pos + 1 - st), set);
//                 cout<<"the modifyRight return with set:";
//                 for (auto t : set) cout<<t<<" "; cout<<'\n';
//                 sets.push_back(set);
//                 st = pos + 1, l = 0, r = 0;
//             }
//             ++pos;
//         }

//         set<string> set;
//         if (l > r)
//         {
//             cout<<"a modifyLeft called for subStr: "<<s.substr(st, s.size() + 1 - st)<<'\n';
//             modifyLeft(s.substr(st, s.size() + 1 - st), 0, 0, 0, l - r, set);
//             cout<<"the modifyLeft return with set:";
//             for (auto t : set) cout<<t<<" "; cout<<'\n';
//         }
//         else set.insert(s.substr(st, s.size() + 1 - st));
//         sets.push_back(set);

//         vector<string> ans;
//         addToAns(sets, ans, 0, "");
//         return ans;
//     }
// };

// 花了18分钟重新写了一版做法，现在是126/129
// 超时，测试样例"))))))))))))))))))))aaaaa"
// 那就很简单了，直接面向答案编程(new_s部分)，这个fix花费2分钟
// class Solution {
// private:
//     void dfs(set<string> &ans, const string &s, string cur, int target, int pos)
//     {
//         if (pos == s.size())
//         {
//             int l = 0, r = 0;
//             for (auto ch : cur)
//             {
//                 if (ch == '(') ++l;
//                 if (ch == ')') ++r;
//                 if (r > l) return;
//             }
//             if (l == target && r == target) ans.insert(cur);
//             return;
//         }

//         //当前字符不删除
//         dfs(ans, s, cur + s[pos], target, pos + 1);
//         //当前字符删除
//         if (s[pos] == '(' || s[pos] == ')') dfs(ans, s, cur, target, pos + 1);
//     }
// public:
//     vector<string> removeInvalidParentheses(string s) {
//         string new_s;
//         bool hasL = false;
//         for (auto t : s)
//         {
//             if (t == '(') hasL = true;
//             else if (t == ')' && !hasL) continue;
//             new_s += t;
//         }
//         s = new_s;
//         // cout<<"now s = "<<s<<"\n";
//         int l = 0, r = 0, sLen = s.size(), target = 0;
//         for (auto ch : s)
//         {
//             if (ch == '(') ++l;
//             if (ch == ')') ++r;
//             if (r > l)
//             {
//                 target += l;
//                 l = 0, r = 0;
//             }
//         }
//         target += min(l, r);
//         set<string> ans;
//         dfs(ans, s, "", target, 0);
//         vector<string> res;
//         for (auto tmp : ans) res.push_back(tmp);
//         return res;
//     }
// };

//通过样例129/129，时间没超，但是超出内存限制，无敌了
//目前总共已经做出了三次尝试，编码分别用时 55分钟（110/129， WA），18分钟（126/129，TLE），2分钟（129/129 MLE）
//事已至此，看题解吧
//看样子之前2分钟的那个fix还是在耍小聪明，还是需要剪枝才行，我们维护需要删除的左括号和右括号数即可剪枝
//懒得自己写一遍了，直接把题解复制过来交了，没什么实现上的细节。不过可以留意一下这里去重的处理手段
class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int lremove = 0;
        int rremove = 0;

        for (char c : s) {
            if (c == '(') {
                lremove++;
            } else if (c == ')') {
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }
        helper(s, 0, lremove, rremove);
        return res;
    }

    void helper(string str, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                res.push_back(str);
            }
            return;
        }
        for (int i = start; i < str.size(); i++) {
            if (i != start && str[i] == str[i - 1]) {
                continue;
            }
            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lremove + rremove > str.size() - i) {
                return;
            }
            // 尝试去掉一个左括号
            if (lremove > 0 && str[i] == '(') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove - 1, rremove);
            }
            // 尝试去掉一个右括号
            if (rremove > 0 && str[i] == ')') {
                helper(str.substr(0, i) + str.substr(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    inline bool isValid(const string & str) {
        int cnt = 0;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                cnt++;
            } else if (str[i] == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
};