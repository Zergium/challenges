class LRUCache {
public:
    
        
    typedef list<int> lru_index_t;
    lru_index_t lru_index;
    
    typedef pair<int, lru_index_t::iterator> value_t;
    unordered_map<int, value_t> key_val;

    int capacity;
    
    LRUCache(int capacity)
        : capacity(capacity) {
        //cout << "capacity: " << capacity << endl;
    }
    
    int get(int key) {
        //cout << "get " << key << endl;
        auto it = key_val.find(key);
        if (it != key_val.end()) {
            value_t& val(it->second);
            lru_index.erase(val.second);
            lru_index.push_front(key);
            val.second = lru_index.begin();
            //cout << "   res: " << val.first << endl;
            return val.first;
        }
        //cout << "   res: -1 (none)" << endl;
        return -1;
    }
    
    void put(int key, int value) {
        //cout << "put " << key << endl;
        auto it = key_val.find(key);
        if (it != key_val.end()) {
            value_t& val(it->second);
            lru_index.erase(val.second);
            lru_index.push_front(key);
            val.second = lru_index.begin();
            val.first = value;
        } else {
            while (lru_index.size() >= capacity) {
                int old_key = lru_index.back();
                lru_index.pop_back();
                key_val.erase(old_key);
            }
            lru_index.push_front(key);
            key_val[key] = {value, lru_index.begin()};
        }
        
        // for (auto kv: key_val) {
        //     cout << "[" << kv.first << ", " << kv.second.first << ",..] ";
        // }
        // cout << endl;
        // for (auto k: lru_index) cout <<  k << " - ";
        // cout << endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */