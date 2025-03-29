//傻逼了，看起来要用并查集，无语
// class Solution {
// private:
//     int uniqueId = 1;
//     string addId(string str)
//     {
//         return str + to_string(uniqueId++);
//     }
//     string subId(string str)
//     {
//         int pos = str.size() - 1;
//         while(str[pos] >= '0' && str[pos] <= '9') --pos;
//         return str.substr(0, pos + 1);
//     }
// public:
//     vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
//         //处理这个问题，应该要给每一个账户名臣给一个独立的名字，下面数据结构中person都是独特化之后的
//         //形如Ethan1 Ethan2
//         unordered_map<string, string> mail2person;
//         unordered_map<string, set<string>> person2set;

//         for (auto account : accounts)
//         {
//             int len = account.size();
//             //先完整遍历一遍，来确定当前账户的归属
//             string master = "-1";
//             for (int i = 1; i < len; ++i)
//             {
//                 if (mail2person.count(account[i])) {master = mail2person[account[i]]; break;}
//             }
//             if (master == "-1") master = addId(account[0]);//创建新的独特id
//             for (int i = 1; i < len; ++i)
//             {
//                 mail2person[account[i]] = master;
//                 person2set[master].insert(account[i]);
//             }
//         }

//         vector<vector<string>> res;
//         for (auto [person, mails] : person2set)
//         {
//             vector<string> tmp;
//             tmp.push_back(subId(person));
//             for (auto mail : mails) tmp.push_back(mail);
//             res.push_back(tmp);
//         }

//         return res;
//     }
// };

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    unordered_map<string, string> parent;  //并查集
    unordered_map<string, string> owner;

    string find(string s) {return parent[s] == s ? s : parent[s] = find(parent[s]);}

    void unionSets(string a, string b)
    {
        string rootA = find(a);
        string rootB = find(b);
        if (rootA != rootB) parent[rootB] = rootA;
    }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //初始化
        for (auto& acc : accounts)
        {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i)
            {
                string email = acc[i];
                if (!parent.count(acc[i]))
                {
                    parent[email] = email;
                    owner[email] = name;
                }
            }
        }
        for (auto& acc : accounts)
        {
            string firstEmail = acc[1];
            for (int i = 2; i < acc.size(); ++i) unionSets(firstEmail, acc[i]);
        }

        unordered_map<string, unordered_set<string>> groups;
        for (auto& [email, p] : parent)
        {
            string root = find(email);
            groups[root].insert(email);
        }

        vector<vector<string>> result;
        for (auto& [root, emails] : groups)
        {
            vector<string> tmp;
            tmp.push_back(owner[root]);
            for (auto email : emails) tmp.push_back(email);
            sort(tmp.begin() + 1, tmp.end());
            result.push_back(tmp);
        }

        return result;
    }
};
