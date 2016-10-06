class Stack {
public:
    queue<int> input;
    queue<int> output;
    // Push element x onto stack.
    void push(int x) {
        input.push(x);
        //insert elements into the back
        for (int i = 1; i < input.size();++i){
            input.push(input.front());
            input.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        input.pop();
    }

    // Get the top element.
    int top() {
        return input.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return input.empty();
    }
};

int main(){

}