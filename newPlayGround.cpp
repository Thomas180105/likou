
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Solution {
private:
    static const int M = 1e6 + 5;
    static const int N = 5005;
    struct Edge{
        int to, nxt;
    }edge[M];
    int head[N], cnt;

    void reset()
    {
        cnt = 0;
        for (int i = 0; i < N; ++i) head[i] = -1;
    }

    void add_edge(int from, int to)
    {
        edge[cnt].to = to;
        edge[cnt].nxt = head[from];
        head[from] = cnt++;
    }

    int get_graph(vector<string>& wordList, const string &beginWord)//返回beginWord在wordList中的索引值，如果不存在就把它push到wordList
    {
        reset();
        int res = -1;
        int l = wordList.size();
        for (int i = 0; i < l; ++i) if (wordList[i] == beginWord) {res = i; break;}
        if (res == -1) {wordList.push_back(beginWord); res = l++;}
        for (int i = 0; i < l; ++i)
        {
            for (int j = i + 1; j < l; ++j)
            {
                //i j l
                if (wordList[i].size() != wordList[j].size()) continue;
                bool flag = false;
                int len = wordList[i].size();
                for (int index = 0; index < len; ++index)
                {
                    if (wordList[i][index] == wordList[j][index]) continue;
                    if (flag) {flag = false; break;}
                    else flag = true;
                }
                if (flag) {add_edge(i, j); add_edge(j, i);}
            }
        }
        return res;
    }

    void dfs(vector<vector<string>> &ans, const vector<string>& wordList, const vector<vector<int>> &pre, int end, int start, int index, vector<int> &cur)
    {
        if (index == start) //暂时认为此时cur中已经有了index
        {
//            std::cout<<"reach a full path!\n";
            int l = cur.size();
            vector<string> pathStr;
            for (int i = l - 1; i >= 0; --i) pathStr.push_back(wordList[cur[i]]);
            ans.push_back(pathStr);
            return;
        }

        int nodePreCnt = pre[index].size();
        for (int i = 0; i < nodePreCnt; ++i)
        {
            cur.push_back(pre[index][i]);
//            cout<<"dfs into "<<pre[index][i]<<endl;
            dfs(ans, wordList, pre, end, start, pre[index][i], cur);
//            cout<<"dfs out of "<<pre[index][i]<<endl;
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> returnVec;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> visited(wordList.size(), false);
        vector<int> dis(wordList.size(), -1);
        int s = get_graph(wordList, beginWord);
        queue<int> que;
        que.push(s);
        dis[s] = 0;

        vector<vector<int>> pre(wordList.size());
        int level = 1, t;
        bool break_flag = false;
        while(!que.empty())
        {
            int loopCnt = que.size();
            if (break_flag) break;
            while(loopCnt--)
            {
                int from = que.front();
                que.pop();
                if (visited[from]) continue;
                visited[from] = true;

                if (wordList[from] == endWord) {t = from; break_flag = true; break;}

                for (int i = head[from]; i != -1; i = edge[i].nxt)
                {
                    if (!visited[edge[i].to])
                    {
                        que.push(edge[i].to);
                        if (dis[edge[i].to] == -1) dis[edge[i].to] = level;
                        if (dis[edge[i].to] > dis[from]) pre[edge[i].to].push_back(from);
                    }
                }
            }
            ++level;
        }
//        cout<<"here is pre:\n";
//        for (int i = 0; i < pre.size(); ++i)
//        {
//            cout<<"pre["<<i<<"] = ";
//            for (int j = 0; j < pre[i].size(); ++j) cout<<pre[i][j]<<" ";
//            cout<<endl;
//        }

        if (!break_flag) return {};

        vector<int> cur{t};
//        cout<<"start = "<<s<<", end = "<<t<<endl;
        dfs(returnVec, wordList, pre, t, s, t, cur);
        cout<<"finish all dfs\n";
//        for (const auto &tmp : returnVec)
//        {
//            for (const auto &str : tmp) cout<<str<<" ";
//            cout<<endl;
//        }
        return returnVec;
    }
};

int main()
{
    Solution s;
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    s.findLadders("hit", "cog", wordList);
    cout<<"we are good!\n";
    return 0;
}
