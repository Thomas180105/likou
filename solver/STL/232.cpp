class MyQueue {
// private:
//     stack<int> info;//top()是队头
//     stack<int> helper;
// public:

//     MyQueue() {

//     }

//     void push(int x) {
//         while(!info.empty()) {helper.push(info.top()); info.pop();}
//         info.push(x);
//         while(!helper.empty()) {info.push(helper.top()); helper.pop();}
//     }

//     int pop() {
//         int res = info.top();
//         info.pop();
//         return res;
//     }

//     int peek() {
//         return info.top();
//     }

//     bool empty() {
//         return info.empty();
//     }
private:
    stack<int> headTop;//top()是队头
    stack<int> tailTop;

    void reverseStack()
    {
        if (headTop.empty()) while(!tailTop.empty()) {headTop.push(tailTop.top()); tailTop.pop();}
        else while(!headTop.empty()) {tailTop.push(headTop.top()); headTop.pop();}
    }
public:

    MyQueue() {

    }

    void push(int x) {
        if (tailTop.empty()) reverseStack();
        tailTop.push(x);
    }

    int pop() {
        if (headTop.empty()) reverseStack();
        int res = headTop.top();
        headTop.pop();
        return res;
    }

    int peek() {
        if (headTop.empty()) reverseStack();
        return headTop.top();
    }

    bool empty() {
        return headTop.empty() && tailTop.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */