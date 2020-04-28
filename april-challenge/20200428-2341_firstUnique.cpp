class FirstUnique {
public:
    list<int> unique;
    unordered_map<int, list<int>::iterator> unique_ptr;
    
    unordered_set<int> multiple;
    FirstUnique(vector<int>& nums) {
        for (int num: nums) {
            add(num);
        }
    }
    
    int showFirstUnique() {
        if (unique.empty()) return -1;
        return unique.front();
    }
    
    void add(int value) {
        
        if (multiple.count(value) > 0) {
            return;
        }
        
        if (unique_ptr.count(value) > 0) {
            multiple.insert(value);
            unique.erase(unique_ptr[value]);
            unique_ptr.erase(value);
        } else {
            unique.push_back(value);
            unique_ptr[value] = prev(unique.end());
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */


/////////////////////////////////


class FirstUnique {
public:
    queue<int> unique;
    unordered_map<int, int> num_counts;
    
    unordered_set<int> multiple;
    FirstUnique(vector<int>& nums) {
        for (int num: nums) {
            int count = ++num_counts[num];
            if (count == 1) {
                unique.push(num);
            }
        }
    }
    
    int showFirstUnique() {
        while (unique.size() > 0 && num_counts[unique.front()]>1) unique.pop();
        if (unique.size() < 1) {
            return -1; 
        }
        return unique.front();
    }
    
    void add(int value) {
        int count = ++num_counts[value];
        if (count == 1) {
            unique.push(value);
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */