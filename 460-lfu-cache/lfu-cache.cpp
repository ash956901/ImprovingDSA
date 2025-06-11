class LFUCache {
    int cap, minf = 0;
    unordered_map<int,int> val, freq;
    unordered_map<int,list<int>> lists;
    unordered_map<int,list<int>::iterator> iters;
public:
    LFUCache(int capacity): cap(capacity) {}

    int get(int key) {
        if (!val.count(key)) return -1;
        int f = freq[key]++;
        
        lists[f].erase(iters[key]);
        
        lists[f+1].push_front(key);
        iters[key] = lists[f+1].begin();
       
        if (lists[minf].empty()) ++minf;
        return val[key];
    }

    void put(int key, int value) {
        if (cap == 0) return;
        if (val.count(key)) {
            val[key] = value;
            get(key); 
            return;
        }
        if (val.size() == cap) {
           
            int old = lists[minf].back();
            lists[minf].pop_back();
            val.erase(old);
            freq.erase(old);
            iters.erase(old);
        }
       
        val[key] = value;
        freq[key] = 1;
        lists[1].push_front(key);
        iters[key] = lists[1].begin();
        minf = 1;
    }
};
