class Solution {
public:
    
    // strategy:
    //
    // from wordList build a graph, (adj nodes)
    //   n = wordList.size()
    //   i={0..n-1}, graph[0..n].adj is a vector of indexes of all adj nodes to it
    // find begin idx and end idx
    // have a bfs implemented from begin to end
    // done
    //
    
    
    /// returns true if only 1 char is different
    bool isDistanceRight(const string& a, const string& b) {
        if (a.size() != b.size()) {
            return false;
        }
        int num_diff_chars(0);
        for (int i=0; i<a.size(); ++i, num_diff_chars < 2) {
            num_diff_chars += (a[i] == b[i]) ? 0 : 1;
        }
        return 1 == num_diff_chars;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        struct node_t {
            vector<int> adj; // adjacent nodes
        }
        
        const int n = wordList.size();
        vector<node_t> graph(n);
        
        for (int i=0; i<n-1; ++i) {
            for (int j=1; j<n; ++j) {
                if (isDistanceRight(a[i], b[j])) {
                    graph[i].adj.push_back(j);
                    graph[j].adj.push_back(i);
                }
            }
        }
        
        int beginIdx = -1;
        int endIdx = -1;
        
        for (int i=0; i<n; ++i) {
            if (a[i] == beginWord) beginIdx = i;
            if (b[i] == endWord) endIdx = i;
        }
        
        // graph is set
        // begin and end idx are set
        // time for BFS
        
        deque< pair<int, int> > queue;
        set<int> visitedNodesIdx;
        
        queue.push_back({beginIdx, 0});
        while (!queue.empty()) {
            pair<int,int> node = queue.front();
            queue.pop_front();
            
            int nodeIdx = node.first;
            int steps = node.second;
            
            for (int nextIdx: graph[nodeIdx].adj) {
                if (nextIdx == endIdx) return (steps + 1);
                if (visitedNodesIdx.end() == visitedNodesIdx.find(nextIdx)) {
                    visitedNodesIdx.push(nextIdx);
                    queue.push_back({nextIdx, steps+1})
                }
            }
        }
       
        //no such transformation found
        return 0;
    }
};