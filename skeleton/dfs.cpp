/*内容：
0. 链式前向星表示有向图的板子
1. 有向图，递归实现/栈实现的dfs
补充说明：
 dfs有很多常见变种应用，见46.cpp（回溯法）
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 + 5;
struct edge{
    int to, next, w;
}e[N];
int head[N], cnt;

int n, m;

void init()
{
    for (int i = 0; i < n; ++i) head[i] = -1;
}

void add(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void print()
{
    for (int i = 0; i < n; ++i)
    {
        std::cout<<"edge from"<<i<<" to ";
        for (int id = head[i]; id != -1; id = e[id].next)
        {
            std::cout<<"( "<<e[id].to<<", "<<id<<", "<<e[id].next<<") ";
        }
        std::cout<<std::endl;
    }
}

bool visited[N];

void dfs(int u){
    visited[u] = true;
    /* Func Begin */
    std::cout << "we are now in " << u << std::endl;
    /* Func End */
    for(int i = head[u]; i != -1; i = e[i].next) if (!visited[e[i].to]) dfs(e[i].to);
}

void dfs_stack(int s){
    stack<int> st;
    st.push(s);
    visited[s] = true;

    while(!st.empty())
    {
       int u = st.top();
       st.pop();
       /* Func Begin */
       std::cout << "we are now in "<< u << std::endl;
       /* Func End */
       for (int i = head[u]; i != -1; i = e[i].next)
       {
           if (!visited[e[i].to]) {visited[e[i].to] = true; st.push(e[i].to);}
       }
    }
}

void reset_visited()
{
    memset(visited, 0, sizeof (visited));
}
/* input
8 8
0 1
0 2
1 2
4 2
4 6
7 6
3 0
3 5
 */

static int main_test()
{
    int u, v, w;
    std::cin >> n >> m;
    init(); //ATTENTION:需要调用初始化函数，且要在n赋值之后再调用
    for (int i = 0; i < m; ++i)
    {
        std::cin>> u >> v;
        add(u, v, 1);
    }

    std::cout << "recursive implementation of dfs\n";
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) dfs(i);
    }

    reset_visited();
    std::cout << "stack implementation of dfs\n";
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i]) dfs_stack(i);
    }
    return 0;
}