class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        typedef pair<string, string> alpha_log_t;
        vector< alpha_log_t > logAlpha;
        vector<string> logDigit;
        for (const auto& log: logs) {
            int idxDelim = log.find(' ');
            string sId = log.substr(0, idxDelim);
            string sRest = log.substr(idxDelim + 1);
            char firstChar = sRest[0];
            bool isDigitLine = firstChar >= '0' && firstChar <= '9';
            if (isDigitLine) {
                logDigit.push_back(log);
            } else {
                logAlpha.push_back({sId, sRest});
            }
        }
        
        sort(logAlpha.begin(), logAlpha.end(), [](alpha_log_t& a, alpha_log_t& b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        
        vector<string> result;
        for (auto& entry: logAlpha) {
            result.push_back(entry.first + ' ' + entry.second);
        }
        for (auto& entry: logDigit) {
            result.push_back(entry);
        }
            
        return result;
            
    }
};