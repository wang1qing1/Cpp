class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {

    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()||minst.top()>val)
        {
            minst.push(val);
        }
        else
        {
            minst.push(minst.top());
        }

    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

