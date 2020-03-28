class MyHashMap {
public:

    struct node_t {
        node_t (int akey, int aval)
            : key(akey)
            , val(aval)
            , next(nullptr) {}
        int key;
        int val;
        node_t* next;
    }
    
    vector<node_t*> m_backets;
    int m_num_backets;
    
    static int calc_hash(int key) {
        return ((key << 5) + key + 0x1a2b3c4d);
    }
    
    static int idx_of_key(int key) {
        return calc_hash(key) % m_num_backets;
    }
    
    /** Initialize your data structure here. */
    MyHashMap() 
        : m_num_backets(100000)
        , m_backets(m_num_backets, nullptr)
        {
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = idx_of_key(key);
        if (m_backets[idx] == nullptr) {
            m_backets[idx] = new node_t(key, value);
        } else {
            node_t* node = m_backets[idx];
            while (node->key != key && node->next != nullptr) {
                node = node->next;
            }
            if (node->key == key) {
                node->val = value;
            } else {
                node->next = new node_t(key, value);
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = idx_of_key(key);
        node_t* node = m_backets[idx];
        while (node != nullptr && node->key != key) {
            node = node->next;
        }
        if (node != nullptr) {
            return node->val;
        } else {
            return -1;
        }
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = idx_of_key(key);
        node_t* node = m_backets[idx];
        if (node != nullptr) {
            if (node->key == key) {
                m_backets[idx] == node->next;
                delete node;
            } else {
                node_t* prev;
                while (nullptr != node && node->key != key) {
                    prev = node;
                    node = node->next;
                }
                if (key == node->key) {
                    prev->next = node->next;
                    delete node;
                }
            }
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