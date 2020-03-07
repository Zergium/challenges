class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int nextWordIdx;
        while (nextWordIdx < words.size()) {
            vector<string> row;
            int charsPicked(words[nextWordIdx].length());
            row.push_back(words[nextWordIdx]);
            nextWordIdx++;
            while (nextWordIdx < words.size() &&
                charsPicked + row.size() + words[nextWordIdx].length() <= maxWidth) {
                charsPicked += words[nextWordIdx].length();
                row.push_back(words[nextWordIdx]);
                nextWordIdx++;
            }

            stringstream line;
            if (row.size() < 2 || nextWordIdx >= words.size()) {
                for (string& word: row) {
                    if (line.tellp() != 0) line << " ";
                    line << word;
                }
                while (line.tellp() < maxWidth) line << " ";
            } else {
                int spacesToSplit = maxWidth - charsPicked;
                int equalSpaces = spacesToSplit / (row.size() - 1);
                int restSpaces = spacesToSplit - (row.size() - 1) * equalSpaces;
                int idxOfSpace = 0;
                for (string& word: row) {
                    if (line.tellp() != 0) {
                        idxOfSpace++;
                        int numSpaces = equalSpaces + ((restSpaces >= idxOfSpace) ? 1 : 0);
                        for (int i=0; i < numSpaces; ++i) {
                            line << " ";
                        }
                    }
                    line << word;
                }
            }
            result.push_back(line.str());
       }
        return result;
    }
};