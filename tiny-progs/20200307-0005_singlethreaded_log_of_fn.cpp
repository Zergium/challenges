class Solution {
public:
    
    struct event_t {
        int fn;
        bool start;
        int ts; // timestamp
        string to_string() {
            stringstream ss;
            ss << fn << ":" << (start?"start":"end") << ":" << ts;
            return ss.str();
        }
    };
    
    event_t strToEvent(string& s) {
        size_t pos1 = s.find(':');
        size_t pos2 = s.find(':', pos1 + 1);
        event_t result;
        result.fn = std::stoi(s.substr(0,pos1));
        result.start = "start" == s.substr(pos1+1, pos2-pos1-1);
        result.ts = std::stoi(s.substr(pos2+1));
        return result;
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        for (auto s: logs) {
            event_t e = strToEvent(s);
            cout << "s: " << s << "  -->  " << e.to_string() << endl;
        }
        return {1};
    }
};