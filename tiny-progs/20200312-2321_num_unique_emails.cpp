class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique;
        for (string s: emails) {
            int idxAt = s.find('@');
            int idxplus = s.find('+');
            if (idxplus < 0) {
                idxplus = idxAt;
            } else {
                idxplus = min(idxplus, idxAt);
            }
            string name = s.substr(0, idxplus);
            string domain = s.substr(idxAt+1);
            stringstream ssname;
            for (char ch: name) {
                if (ch == '.') continue;
                ssname << ch;
            }
            ssname << '@' << domain;
            unique.insert(ssname.str());
        }
        return unique.size();
    }
};