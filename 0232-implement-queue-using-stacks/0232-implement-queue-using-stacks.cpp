class MyQueue {
public:
    stack<int>first;
    stack<int>second;
    int topElement=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(first.empty()){
            topElement=x;
        }
        first.push(x);
    }
    
    int pop() {
    
        if(second.empty()){
            while(!first.empty()){
                second.push(first.top());
                first.pop();
            }
        }
        int temp=second.top();
    second.pop();
     return temp;
    }
    
    int peek() {
        
        return !second.empty()?second.top():topElement;
    }
    
    bool empty() {
        return first.empty() && second.empty();
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