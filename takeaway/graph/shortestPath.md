# 最短路算法代码板子

## 1. Floyd算法（全源最短路径）

```cpp
void floyd(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}
```

## 2. Dijkstra算法（单源最短路径）

```cpp
void dijkstra(vector<vector<pair<int, int>>>& graph, int src, vector<int>& dist) {
    int n = graph.size();
    dist.assign(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

## 3. Bellman-Ford算法（单源最短路径）

```cpp
bool bellmanFord(vector<vector<int>>& edges, int n, int src, vector<int>& dist) {
    dist.assign(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; ++i) {//每次用边来松弛操作，不存在父权环的时候最多n-1条边，故n-1次即可
        bool updated = false;
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                updated = true;
            }
        }
        if (!updated) break;
    }
    // 检查负权环
    for (auto& e : edges) {
        int u = e[0], v = e[1], w = e[2];
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
            return false; // 存在负权环
        }
    }
    return true;
}
```

# 最短路算法分析（Floyd/Dijkstra/Bellman-Ford）

## 1. Floyd算法（全源最短路径）

### 正确性证明
基于动态规划，定义`dist[k][i][j]`表示从`i`到`j`且仅经过前`k`个顶点的最短路径。
证明前提，图中不存在父权环，这样两个点之间的最短路径不可能同时经过一个节点两次，所以下面可以使用类似01背包的做法而不是完全背包

**状态转移方程**：

dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])


**归纳证明**：
1. 假设`dist[k-1][i][j]`已计算正确
2. 最短路径要么不经过`k`（保持原值），要么经过`k`（拆分为i→k和k→j）
3. 当`k=n`时得到全局最短路径

### 时间复杂度分析
- 三重循环：O(n^3)
- 适用场景：
  - 稠密图（边数接近n²）
  - 可处理负权边，不能处理负权环

---

## 2. Dijkstra算法（单源最短路径）

### 正确性证明
基于贪心策略，每次选择当前距离最小的未访问节点。

**关键性质**：
1. 非负权边保证已确定最短路径不会被后续更新
2. 优先队列保证每次取出的是当前最小dist节点

**归纳证明**：
1. 初始`dist[src]=0`正确
2. 假设前k个节点已计算正确
3. 选择最小dist[u]，因其不会被后续更新，故已是最优
4. 松弛u的所有邻居v

### 时间复杂度分析
- 优先队列实现：O((n+m)logn)
- 斐波那契堆优化：O(m+nlogn)
- 适用场景：
  - 非负权图
  - 稀疏图（m≈n）

---

## 3. Bellman-Ford算法（单源最短路径）

### 正确性证明
基于动态规划，`dist[k][v]`表示从src到v最多经过k条边的最短路径。

**状态转移方程**：
```
dist[k][v] = min(dist[k-1][v], min_{(u,v)∈E}(dist[k-1][u]+w(u,v)))
```

**归纳证明**：
1. 最短路径最多n-1条边（否则有负权环）
2. 第n轮仍能更新说明存在负权环

### 时间复杂度分析
- 外层n-1次，内层遍历所有边：O(n·m)
- 适用场景：
  - 可处理负权边
  - 可检测负权环
  - 适合稀疏图

---

## 对比总结

| 算法          | 时间复杂度       | 适用场景          | 负权边 | 负权环检测 |
|---------------|------------------|-------------------|--------|------------|
| Floyd         | O(n³)            | 稠密图            | 可以   | 不能       |
| Dijkstra      | O((n+m)logn)     | 非负权图          | 不能   | 不能       |
| Bellman-Ford  | O(n·m)           | 稀疏图/负权图     | 可以   | 可以       |

## 如何选择？

一般是直接使用dijsktra算法，因为其时间复杂度较低，但其存在局限性，当出现下面情况时，一般另寻高明

- 如果要求全源最短路，一般中直接上Floyd即可（编码方便 ）
- 如果要求单源最短路
    - 图中存在负权边：Bellman-Ford
    - 需要检测从起点开始是否有可达的负权环：Bellman-Ford
    - 需要限制边的数量时：Bellman-Ford

# 最短路算法题目
- 2959
- 787
- 743