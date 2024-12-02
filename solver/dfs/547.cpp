#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int N = 205;
        bool visited[205];
        int n = isConnected.size();
        int ans = 0;
        for (int i = 0; i < N; ++i) visited[i] = false;
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                ++ans;
                stack<int> st;
                st.push(i);

                while(!st.empty())
                {
                    int u = st.top();
                    st.pop();
                    if (visited[u]) continue;
                    visited[u] = true;
                    for (int id = 0; id < n; ++id)
                    {
                        if (isConnected[u][id] && !visited[id]) st.push(id);
                    }
                }
            }
        }
        return ans;
    }
};