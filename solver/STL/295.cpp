//纯纯数据结构教材题，用两个堆即可
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> minHalf;//大根堆
    priority_queue<int, vector<int>, greater<int>> maxHalf;//小根堆
public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (minHalf.empty() || num > minHalf.top()) //这里注意特判一下empty
        {
            maxHalf.push(num);
            if (maxHalf.size() > minHalf.size())
            {
                int tmp = maxHalf.top();
                maxHalf.pop();
                minHalf.push(tmp);
            }
        }
        else
        {
            minHalf.push(num);
            if (maxHalf.size() + 1 < minHalf.size())
            {
                int tmp = minHalf.top();
                minHalf.pop();
                maxHalf.push(tmp);
            }
        }
    }

    double findMedian() {
        if (minHalf.size() == maxHalf.size()) return (static_cast<double>(minHalf.top()) + maxHalf.top()) / 2;
        return minHalf.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */