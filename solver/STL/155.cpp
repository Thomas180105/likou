class MinStack {
private:
    stack<int> data;
    stack<int> localMin;
public:
    MinStack() {

    }

    void push(int val) {
        data.push(val);
        localMin.push(localMin.empty() ? val : min(localMin.top(), val));
    }

    void pop() {
        data.pop();
        localMin.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return localMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */