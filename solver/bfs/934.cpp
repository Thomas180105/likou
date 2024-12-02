#include<stack>
#include<vector>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
private:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        if (!n) return 0;
        //先使用dfs找到第一个岛屿（对应grid中的1覆写为2，同时把这一块岛屿的点进队列）
        queue<pair<int, int>> que;
        bool flag = false;
        for(int i = 0; i < n; ++i)
        {
            if (flag) break;
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]) {dfs(grid, que, i, j, n); flag = true; break;}
            }
        }

        std::cout<<"here is after dfs():\n";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j) std::cout<<grid[i][j]<<" ";
            std::cout<<std::endl;
        }

        //再利用bfs找到两者之间的距离(中途0->2, 2continue, 1return)
        int ans = 0;
        while(true)
        {
            int curLoop = que.size();
            while(curLoop--)
            {
                auto [r, c] = que.front();
                que.pop();

                for (int i = 0; i < 4; ++i)
                {
                    int rr = r + dr[i], cc = c + dc[i];
                    if (rr >= 0 && rr < n && cc >= 0 && cc < n)
                    {
                        if (grid[rr][cc] == 1) return ans;
                        else if (grid[rr][cc] == 0)
                        {
                            grid[rr][cc] = 2;
                            que.push({rr, cc});
                        }
                    }
                }
            }
            ++ans;
        }
    }
private:
    void dfs(vector<vector<int>> &grid, queue<pair<int, int>> &que, int r, int c, int n)
    {
        grid[r][c] = 2;
        que.push({r, c});

        for (int i = 0; i < 4; ++i)
        {
            int rr = r + dr[i], cc = c + dc[i];
            //==1包含了两层含义，首先是这是岛屿，其次这里没有被访问过 
            if (rr >= 0 && rr < n && cc >= 0 && cc < n && grid[rr][cc] == 1) dfs(grid, que, rr, cc, n);
        }
    }
};

int main_test()
{
    vector<vector<int>> grid{{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    Solution s;
    cout << s.shortestBridge(grid) << endl;
    return 0;
}