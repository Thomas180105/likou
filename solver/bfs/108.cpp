//==以及strcmp，class中要加static，
#include <queue>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Solution {
private:
    static const int M = 250005;
    static const int N = 505;
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

        for (int from = 0; from < l; ++from)
        {
            cout<<"edge from "<<from<<" to ";
            for (int i = head[from]; i != -1; i = edge[i].nxt) cout<<edge[i].to<<" ";
            cout<<"\n";
        }
        return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int s = get_graph(wordList, beginWord);
        queue<int> que;
        que.push(s);

        vector<bool> visited(wordList.size(), false);
        int level = 1;
        while(!que.empty())
        {
            int loopCnt = que.size();
            while(loopCnt--)
            {
                int from = que.front();
                que.pop();
                if (visited[from]) continue;
                visited[from] = true;

                if (wordList[from] == endWord) return level;

                for (int i = head[from]; i != -1; i = edge[i].nxt)
                {
                    if (!visited[edge[i].to]) que.push(edge[i].to);
                }
            }
            ++level;
        }
        return 0;
    }
};
static int test_main()
{
    std::cout<<"this is 108\n";
    Solution sol;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout<<sol.ladderLength(beginWord, endWord, wordList)<<endl;
    return 0;
}
// hot 0 dot 1 dog 2 lot 3 log 4 cog 5 hit 6