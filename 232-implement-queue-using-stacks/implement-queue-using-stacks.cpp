class MyQueue {
public:
        stack<int> s1;
        stack<int> s2;
    MyQueue() {
      
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }
        else{
            //take out all elements of stack s1 and store in stack s2
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }

            //now push the new element into stack s1
            s1.push(x);

            //now in order take out all the elements from s2 and store in stack s1
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        //whenever you pop in a queue , the element from the front goes , so just do normal pop for stack s1
      
              int rem=s1.top();
              s1.pop();
              return rem;
     
    }
    
    int peek() {
      
            return s1.top();
       
    }
    
    bool empty() {
        if(!s1.empty()) return false;
        return true; 
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