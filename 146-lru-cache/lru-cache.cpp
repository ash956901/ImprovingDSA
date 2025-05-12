class LRUCache {
    int capacity;
    list<pair<int,int>> lt;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        auto it=mp[key];
        lt.splice(lt.begin(),lt,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            auto it=mp[key];
            it->second=value;
            lt.splice(lt.begin(),lt,it);
            return;
        }
        else{
            if(lt.size()==capacity){
                int k=lt.back().first;
                lt.pop_back();
                mp.erase(k);
            }

            lt.push_front(make_pair(key,value));
            mp[key]=lt.begin();
            return;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */