//下面是完全不work的废弃代码
// class Solution {
// private:
//     void dfs(vector<int> &res, string stamp, string &target, int st, int ed, bool &flag)
//     {
//         if (st > ed) {flag = true; return;}
//         if (target[st] != stamp[0] && target[ed] != stamp.back()) {flag = false; return;}
//         int sLen = stamp.size(), left, right;

//         string backup = target;

//         for (left = 0; left < sLen; ++left) if (stamp[left] != target[left + st]) break;
//         if (left != 0)
//         {
//             for (int i = left; i < sLen; ++i) target[st + i] = stamp[i];
//             res.push_back(st);

//             cout<<"[to left] now the res is : ";
//             for (auto t : res) cout<<t<<" ";
//             cout<<"\ntarget is "<<target<<" now we are going to dfs("<<st + left<<", "<<ed<<")\n";
//             dfs(res, stamp, target, st + left, ed, flag);
//             if (flag) return;
//             res.pop_back();
//             target = backup;
//             cout<<"[from left] now the res is : ";
//             for (auto t : res) cout<<t<<" ";
//             cout<<"\ntarget is"<<target<<" now we are returning from dfs("<<st + left<<", "<<ed<<")\n";
//         }

//         for (right = sLen - 1; right >= 0; --right) if (stamp[right] != target[ed - sLen + right + 1]) break;
//         if (right != sLen - 1)
//         {
//             for (int i = right; i >= 0; --i) target[ed - sLen + i + 1] = stamp[i];
//             res.push_back(ed - sLen + 1);
//             cout<<"[to right] now the res is : ";
//             for (auto t : res) cout<<t<<" ";
//             cout<<"\ntarget is "<<target<<" now we are going to dfs("<<st + left<<", "<<ed<<")\n";
//             dfs(res, stamp, target, st, ed - right, flag);
//             if (flag) return;
//             res.pop_back();
//             target = backup;

//             cout<<"[from right] now the res is : ";
//             for (auto t : res) cout<<t<<" ";
//             cout<<"\ntarget is "<<target<<" now we are going to dfs("<<st + left<<", "<<ed<<")\n";
//         }
//     }
// public:
//     vector<int> movesToStamp(string stamp, string target) {
//         int len = target.size();
//         vector<int> res;
//         bool flag;
//         dfs(res, stamp, target, 0, len - 1, flag);
//         if (flag) return res;
//         return {};
//     }
// };

class Solution {
private:
    bool checkAndModify(const string &stamp, string &target, int index)
    {
        bool flag = true;
        for (int i = 0, len = stamp.size(); i < len; ++i) if (target[i + index] != '?' && target[i + index] != stamp[i]) {flag = false; break;}
        if (flag) for (int i = 0, len = stamp.size(); i < len; ++i) target[index + i] = '?';
        return flag;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        int sLen = stamp.size(), tLen = target.size();
        vector<int> res;
        while(target != string(tLen, '?'))
        {
            bool flag = false;
            for (int i = 0; i <= tLen - sLen; ++i)
            {
                if (target.substr(i, sLen) == string(sLen, '?')) continue;
                if (checkAndModify(stamp, target, i)) {flag = true; res.push_back(i);/*cout<<"now target = "<<target<<'\n';*/}
            }
            if (!flag) break;
        }
        if (target != string(tLen, '?')) return {};
        reverse(res.begin(), res.end());
        return res;
    }
};