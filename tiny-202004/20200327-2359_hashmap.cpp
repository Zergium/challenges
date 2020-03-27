class MyHashMap {
public:
    
    typedef pair<int,int> item_t;
    typedef vector<item_t> backet_t;
    typedef vector<backet_t> backets_t;
    
    int m_num_backets;
    backets_t m_backets;
    
    static int calc_hash(int key) {
        return ((key << 5) + key + 0x1a2b3c4d);
    }
    
    int calc_backet_for_key(int key) {
        return (calc_hash(key) % m_num_backets);
    }
    
    /** Initialize your data structure here. */
    MyHashMap() 
        : m_num_backets(100000)
        , m_backets(m_num_backets)
        {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        backet_t& backet = get_backet(key);
        if (backet.size() == 0) {
            backet.push_back({key, value});
        } else {
            auto it = get_item_iterator(backet, key);
            if (it != backet.end()) {
                (*it).second = value;
            } else {
                backet.push_back({key, value});
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        backet_t& backet = get_backet(key);
        auto it = get_item_iterator(backet, key);
        if (it != backet.end()) {
            return (*it).second;
        } else {
            return -1;
        }
    }

    backet_t& get_backet(int key) {
        return m_backets[calc_backet_for_key(key)];
    }
    backet_t::iterator get_item_iterator(backet_t& backet, int key) {
        auto it = find_if(backet.begin(), backet.end(), 
                       [=](const item_t& v) {return v.first == key;});
        return it;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        backet_t& backet = get_backet(key);
        auto it = get_item_iterator(backet, key);
        if (it != backet.end()) {
            backet.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */