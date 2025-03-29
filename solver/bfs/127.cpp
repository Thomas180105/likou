class Solution {
private:
    bool isSimilar(const string &a, const string &b)//确保两者长度相同
    {
        bool flag = false;
        for (int i = 0, len = a.size(); i < len; ++i)
        {
            if (a[i] != b[i])
            {
                if (!flag) flag = true;
                else return false;
            }
        }
        return flag;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //想法就是建图之后跑一个dfs
        //实现来说，wordList就是将string映射到节点(int)的天然容器，然后我们需要一个int到string的映射，然后是建图graph
        int st = -1, ed = -1;
        for (int i = 0, len = wordList.size(); i < len; ++i)
        {
            if (wordList[i] == beginWord) st = i;
            if (wordList[i] == endWord) ed = i;
        }
        if (ed == -1) return 0;
        if (st == -1)
        {
            wordList.push_back(beginWord);
            st = wordList.size() - 1;
        }

        int n = wordList.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (isSimilar(wordList[i], wordList[j]))
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);//跑bfs，直接在入que的时候就可以处理
        queue<int> que;
        que.push(st);
        visited[st] = true;

        for (int step = 2; !que.empty(); ++step)
        {
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i)
            {
                int cur = que.front();
                que.pop();

                //由于是bfs写法，这里就不用判断viisted了
                for (auto son : graph[cur])
                {
                    if (!visited[son])
                    {
                        if (son == ed) return step;
                        visited[son] = true;
                        que.push(son);
                    }
                }
            }
        }
        return 0;
    }
};