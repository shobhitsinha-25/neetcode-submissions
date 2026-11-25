class MinStack {
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.size()!=0)
        {
            if(val<=minst.top()) minst.push(val);
        }
        else minst.push(val);
    }
    
    void pop() {
        if(st.size()==0) return;
        if(st.top()==minst.top())
        {
            st.pop();
            minst.pop();
        }
        else st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
