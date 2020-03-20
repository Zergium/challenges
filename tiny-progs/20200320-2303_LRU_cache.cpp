// https://leetcode.com/problems/lru-cache/

class LRUCache {
    int m_capacity;
    list<int> m_keys;
    struct item_t {
        list<int>::iterator it;
        int val;
        item_t(list<int>::iterator a_it, int a_val)
            : it(a_it)
            , val(a_val)
            {};
        item_t(){};
    };
    unordered_map<int, item_t> m_key_to_item;
public:
    LRUCache(int capacity) : m_capacity(capacity) {
        
    }
    
    int get(int key) {
        auto it = m_key_to_item.find(key);
        if (it != m_key_to_item.end()) {
            m_keys.erase(it->second.it);
            m_keys.push_back(key);
            it->second.it = prev(m_keys.end());
            return it->second.val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = m_key_to_item.find(key);
        if (it != m_key_to_item.end()) {
            m_keys.erase(it->second.it);
            m_keys.push_back(key);
            it->second.it = prev(m_keys.end());
            it->second.val =  value;
        } else {
            m_keys.push_back(key);
            item_t x(prev(m_keys.end()), value);
            m_key_to_item[key] = x;
            while (m_keys.size() > m_capacity) {
                int key_to_del = m_keys.front();
                m_keys.pop_front();
                m_key_to_item.erase(key_to_del);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */