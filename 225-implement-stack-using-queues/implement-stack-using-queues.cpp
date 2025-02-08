class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    
    }
    
    void push(int x) {
       if(q1.empty()) q1.push(x);
       else{
        //remove all elements from q1, push to q2 to maintain stack like order 
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        //now push the new element into q1
        q1.push(x);

        //now copy all the elements back from the queue q2
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
       }
    }
    
    int pop() {
        int ret= q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {
         //its very convenient,since all calls valid and we followed the insertion order, just return the front element of the q1
         return q1.front();
    }
    
    bool empty() {
        if(!q1.empty()){
            return false;
        }
        return true;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */