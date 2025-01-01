class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto tmp : prerequisites)
        {
            ++inDegree[tmp[0]];
            graph[tmp[1]].push_back(tmp[0]);
        }

        queue<int> que;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!inDegree[i]) que.push(i);
        }

        vector<int> ans;
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            ans.push_back(cur);

            for (auto son : graph[cur]) if (!(--inDegree[son])) que.push(son);
        }

        if (ans.size() != numCourses) return {};
        return ans;
    }
};