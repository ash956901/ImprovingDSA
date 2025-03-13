class StockSpanner {
public:
    stack<int> s;
    vector<int> sv;
    int i;
    StockSpanner() {
       i=0;
    }
    
    int next(int price) {
        sv.push_back(price);
        while(!s.empty() && sv[s.top()]<=sv[i]){
            s.pop();
        }

        int ret=i+1;
        if(!s.empty()){
            ret=i-s.top();
        }
       
        s.push(i);
        i++;
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */