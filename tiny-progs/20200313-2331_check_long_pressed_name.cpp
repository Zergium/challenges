class Solution {
public:
    
    pair<char, int> getNextCharAndLen(const string& str, int& idx) {
        char ch = str[idx];
        // a
        
        int len = 1;
        idx++; 
        // 1
        
        while (idx < str.size() && str[idx] == ch) {
            idx++;
            len++;
        }
        return {ch, len};
        // a 1
    }
    
    bool isLongPressedName(string name, string typed) {
        // name = alex
        // typed = aaleex
        int i = 0, j = 0;
        
        while (i < name.size() && j < typed.size()) {
            
            auto ch_name = getNextCharAndLen(name, i);
            //cout << "1: " << ch_name.first << " = " << ch_name.second << endl;
            // 
            
            auto ch_typed = getNextCharAndLen(typed, j);
            //cout << "2: " << ch_typed.first << " = " << ch_typed.second << endl;
            
            if (ch_name.first != ch_typed.first) return false;
            if (ch_name.second > ch_typed.second) return false;
        }
        bool len_is_same = (i == name.size() && j == typed.size());
        //cout << "len is same: " << i << " vs " << name.size() << ";  " << j << " vs " << typed.size() << " ---> " << (len_is_same?"Y":"N") <<endl;
        return len_is_same;
    }
};