class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);

        for (auto tmp : prerequisites)
        {
            ++inDegree[tmp[0]];
            graph[tmp[1]].push_back(tmp[0]);
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i) if (!inDegree[i]) que.push(i);

        int cnt = 0;
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            ++cnt;

            for (auto son : graph[cur]) if (!--inDegree[son]) que.push(son);
        }

        return cnt == numCourses;
    }
};