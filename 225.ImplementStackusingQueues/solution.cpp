class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!tempQueue.empty()) {
            tempQueue.pop();
        }
        tempQueue.push(x);
        while(!myQueue.empty()) {
            int temp = myQueue.front(); myQueue.pop();
            tempQueue.push(temp);
        }
        myQueue = tempQueue;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = myQueue.front(); myQueue.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return myQueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
    }

private:
    queue<int> myQueue;
    queue<int> tempQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
