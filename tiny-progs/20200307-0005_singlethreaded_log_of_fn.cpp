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
        deque<int> callstack;
        vector<int> times_of_fn(n, 0);
        int now = -1;
        int prev_start = -1;
        for (auto s: logs) {
            event_t e = strToEvent(s);
            if (e.start) {
                if (now >= 0) {
                    times_of_fn[now] += e.ts - prev_start;
                    callstack.push_back(now);
                }
                now = e.fn;
                prev_start = e.ts;
            } else {
                if (now != e.fn) {
                    cout << "!!! finishing wrong fn";
                };
                times_of_fn[now] += e.ts - prev_start + 1;
                if (callstack.empty()) {
                    now = -1;
                } else {
                    now = callstack.back();
                    callstack.pop_back();
                }
                prev_start = e.ts + 1;
            }
            //cout << "s: " << s << "  -->  " << e.to_string() << endl;
        }
        return times_of_fn;
    }
};