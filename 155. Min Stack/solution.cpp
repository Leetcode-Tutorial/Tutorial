class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>st;         //初始化俩个栈
    stack<int>minSt;
    
    MinStack() {
            
    }
    
    void push(int x) {
        st.push(x);
        if (minSt.empty()||x <= minSt.top())
            minSt.push(x);
        
    }
    
    void pop() {
        if(st.empty())
            return;
        if(st.top()==minSt.top())
            minSt.pop();
        st.pop();
    }
    
    int top() {
        if(st.empty())
            return -1;
        else
            return st.top();
    }
    
    int getMin() {
         if (st.empty()) return -1;
           else return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */