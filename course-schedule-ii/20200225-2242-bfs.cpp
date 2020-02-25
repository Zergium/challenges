/// Runtime: 20 ms, faster than 95.90% of C++ online submissions
/// Memory Usage: 13.2 MB, less than 100.00% of C++ online submissions

class Solution {
public:
    
    // plan
    //  1. build graph, adj style, root(s) are courses with 0 dependency
    // 1a. nodes to keep amount of dependent courses

    // 2. prepare result vector (courses idx)
    // 3. do bfs-kind iteration:
    // 4. pick a node from queue, iterate through all-sub nodes dec by 1 their dependency counter (they may have many parent roots)
    //    put to the queue only nodes with 0 dependency counter
    // 5. repeat till queue will be empty
    // 6. if # of items in result is < then amount courses - it were loops! return empty result

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        struct node_t {
            node_t() 
                : numDependentOn(0) {}
            vector<int> adj;
            int numDependentOn;
        };
        
        vector<node_t> graph(numCourses);
        
        for (const auto& node: prerequisites) {
            graph[node[1]].adj.push_back(node[0]);
            graph[node[0]].numDependentOn++;
        }
        
        vector<int> result;

        deque<int> queue;
        for (int idx = 0; idx < numCourses; ++idx) {
            if (graph[idx].numDependentOn == 0) {
                queue.push_back(idx);
            }
        }
        
        while (!queue.empty()) {
            int idx = queue.front();
            queue.pop_front();
            result.push_back(idx);
            
            for (int childIdx: graph[idx].adj) {
                graph[childIdx].numDependentOn--;
                if (graph[childIdx].numDependentOn == 0) {
                    queue.push_back(childIdx);
                }
            }
        }
        
        if (result.size() != numCourses) {
            result.clear();
        }
        return result;
    }
};