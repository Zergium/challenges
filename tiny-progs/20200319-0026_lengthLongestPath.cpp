class Solution {
public:
    int lengthLongestPath(string input) {
        deque <pair<int,string>> paths; // indent + name
        int pathlen = 0;
        int result = 0;
        for (int i=0; i<input.size(); ++i) {
            int indent = 0;
            while (i < input.size() && input[i] == '\t') {
                indent++;
                i++;
            }
            string name;
            while (i < input.size() && input[i] != '\n') {
                name += input[i];
                i++;
            }
            
            //trim_str(name);
            bool is_dir = (string::npos == name.find('.'));
            

            while (!paths.empty() && paths.back().first >= indent) {
                pathlen -= paths.back().second.length() + 1;
                paths.pop_back();
            }
            if (is_dir) {
                paths.push_back({indent,name});
                pathlen += name.length() + 1;
            } else {
                int len = pathlen + name.length();
                if (len > result) result = len;
            }
            
        }
        return result;
    }
};