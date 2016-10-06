class MinStack {
private:
    vector<int> vect;
    int min;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (vect.empty()) min = x;
        else min = (x >= s.top())?s.top():x;
        s.push(min);
        vect.push_back(x);
    }
    
    void pop() {
        s.pop();
        vect.pop_back();
    }
    
    int top() {
        return vect.back();
    }
    
    int getMin() {
        return s.top();
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