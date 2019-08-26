class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        _myqueue.push_back(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int res = top();
        _myqueue.pop_back();
        return res;
    }

    /** Get the top element. */
    int top()
    {
        return *(_myqueue.end() - 1);
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return _myqueue.empty();
    }

private:
    std::deque<int> _myqueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
