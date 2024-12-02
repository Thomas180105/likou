#include<stack>
#include<vector>
#include<cmath>
using namespace std;
struct point{
    int x, y;
    point(int x, int y):x(x), y(y){}
};
class Solution {
public:
    int n, m;
    bool isInBorad(point p) {return p.x >= 0 && p.x < n && p.y >= 0 && p.y < m;}
    vector<int> dx{0, 0, 1, -1};
    vector<int> dy{1, -1, 0, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int N = 55;
        int visited[N][N];
        if (grid.empty()) return 0;
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j) visited[i][j] = 0;
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    int res = 0;
                    stack<point> st;
                    st.push(point(i, j));

                    while(!st.empty())
                    {
                        point u = st.top();
                        st.pop();

                        if (!visited[u.x][u.y])
                        {
                            ++res;
                            visited[u.x][u.y] = true;
                            for (int t = 0; t < 4; ++t)
                            {
                                point v(u.x + dx[t], u.y + dy[t]);
                                if (isInBorad(v) && grid[v.x][v.y] && !visited[v.x][v.y]) st.push(v);
                            }
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};