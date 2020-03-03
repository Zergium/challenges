class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
      unordered_set<string> ms(wordList.begin(), wordList.end());
      queue<string> todo;
      int level = 1;
      if(beginWord == endWord) return level;
      todo.push(beginWord);
      while(!todo.empty())
      {
        int size = todo.size();
        ++level;
        for(int i=0; i<size; ++i)
        {
          string word = todo.front();
          todo.pop();
          for(int j=0; j<word.size(); ++j)
          {
            string temp = word;
            for(char c = 'a'; c<='z'; ++c)
            {
              temp[j] = c;
              if(ms.find(temp) != ms.end())
              {
                ms.erase(temp);
                if(temp == endWord)
                {
                  return level;
                }
                todo.push(temp);
              }
            }
          }
        }
      }
      return 0;
    }
};