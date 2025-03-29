class Solution {
public:
    string alienOrder(vector<string>& words) {
        //相当于给了若干不等式，最后要给一个大小排序使得所有不等式被满足
        //不等式等效于图中的连边，合法的大小排序等效于图上的拓扑排序
        //不等式应该是n^2个而不是n个，比如["wrt","wrf","er"]不止（"wrt", "wrf"）（"wrt", "er"）有信息，（"wrt", "er"）也有，这样时间复杂度O(N^2*M)

        int n = words.size();
        unordered_map<char, unordered_set<char>> graph(n);//可能被重复添加边，所以要用哈希表来存放
        unordered_map<char, int> inDeg;

        //单词之间提供信息
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                //将words[i] 和words[j]提供的信息建图
                int len = min(words[i].size(), words[j].size());
                bool flag = true;
                for (int pos = 0; pos < len; ++pos)
                {
                    if (words[i][pos] != words[j][pos])
                    {
                        if (!graph[words[i][pos]].count(words[j][pos]))
                        {
                            // cout<<"when compare word "<<i<<" and "<<j<<", we find "<<words[i][pos]<<" point to "<<words[j][pos]<<'\n';
                            graph[words[i][pos]].insert(words[j][pos]);
                            ++inDeg[words[j][pos]];
                        }
                        flag = false;
                        break;
                    }
                }
                if (flag && words[i].size() > words[j].size()) return "";//通过数121/122，没过的点是["abc","ab"]，打了个补丁
            }
        }

        unordered_set<char> charSet;
        for (int i = 0; i < n; ++i) for (auto ch : words[i]) charSet.insert(ch);

        string res;
        queue<char> que;
        for (auto ch : charSet) if (!inDeg[ch]) que.push(ch);
        while(!que.empty())
        {
            auto cur = que.front();
            que.pop();
            res += cur;

            for (auto nxt : graph[cur])
            {
                if (!--inDeg[nxt]) que.push(nxt);
            }
        }

        // cout<<"the res is "<<res<<'\n';
        return res.size() == charSet.size() ? res : "";
    }
};