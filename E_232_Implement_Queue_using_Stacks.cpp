
class Queue {
public:
    stack<int> s;
    stack<int> q;
    // Push element x to the back of queue.
    void push(int x) {  
        s.push(x);

    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        q.pop();
        while(!q.empty()){
            s.push(q.top());
            q.pop();
        }
        
    }

    // Get the front element.
    int peek(void) {
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        int rval = q.top();
        while(!q.empty()){
            s.push(q.top());
            q.pop();
        }
        return rval;   
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
int main(){
	
}