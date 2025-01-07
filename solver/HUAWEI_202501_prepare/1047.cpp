//用时；01：58
class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> vec;
        for (auto cur : s)
        {
            if (!vec.empty() && cur == vec.back()) vec.pop_back();
            else vec.push_back(cur);
        }
        string res;
        for (auto ch : vec) res += ch;
        return res;

    }
};