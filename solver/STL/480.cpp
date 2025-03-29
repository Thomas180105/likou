//相当于是昨天那个求中位数题目加一个懒删除
//需要维护的不变量（性质）：堆顶数字未被删除、两个堆大小之间的关系
//需要维护的变量：两个size两个堆一个哈希
class Solution {
private:
    priority_queue<int, vector<int>, less<int>> minHalf;
    priority_queue<int, vector<int>, greater<int>> maxHalf;
    unordered_map<int, int> toDel;//数字->要删除几次
    int minSize = 0;
    int maxSize = 0;

    //最开始堆满足不变量：堆顶的数字是合法的（不是待删除的数字），后续只需要维持这个不变量就行
    //不变量破坏可能且只可能在涉及到pop的时候发生
    template<typename T>
    void checkTop(T &que)
    {
        while(!que.empty() && toDel.count(que.top()))
        {
            if (!--toDel[que.top()]) toDel.erase(que.top());
            que.pop();
        }
    }

    //最开始两个堆满足两者大小关系的不变量，后续要维持
    //不变量的破坏可能在插入和删除中
    void adjust()
    {
        if (minSize > maxSize + 1)
        {
            --minSize;
            ++maxSize;
            maxHalf.push(minHalf.top());
            minHalf.pop();
            checkTop(minHalf);
        }
        else if (minSize < maxSize)
        {
            ++minSize;
            --maxSize;
            minHalf.push(maxHalf.top());
            maxHalf.pop();
            checkTop(maxHalf);
        }
    }

    void erase(int num)
    {
        ++toDel[num];
        if (minHalf.top() >= num) --minSize;
        else --maxSize;
        if (minHalf.top() == num) checkTop(minHalf);
        if (maxHalf.top() == num) checkTop(maxHalf);
        adjust();
    }

    void insert(int num)
    {
        if (minHalf.empty() || num <= minHalf.top())
        {
            ++minSize;
            minHalf.push(num);
            adjust();
        }
        else
        {
            ++maxSize;
            maxHalf.push(num);
            adjust();
        }
    }

    double getMedium(int k)
    {
        return k & 1 ? minHalf.top() : (static_cast<double>(minHalf.top()) + maxHalf.top()) / 2;
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0, len = nums.size(); i < len; ++i)
        {
            insert(nums[i]);
            if (i >= k) erase(nums[i - k]);
            if (i >= k - 1) res.push_back(getMedium(k));
        }
        return res;
    }
};