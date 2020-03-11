class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        struct node_t {
          vector<int> adj;
        };
        vector<node_t> graph(M.size());
        for (int i=0; i<M.size(); i++) {
            for (int j=0; j<M.size(); j++) {
                if (M[i][j] > 0) {
                    graph[i].adj.push_back(j);
                    graph[j].adj.push_back(i);
                }
            }
        }
        
        int numClusters = 1;
        vector<bool> checked(M.size());
        int numChecked = 1;
        checked[0] = true;
        deque<int> pos;
        pos.push_back(0);
        

        while (!pos.empty()) {
            while (!pos.empty()) {
                int idx = pos.front();
                pos.pop_front();
                for (int nxt: graph[idx].adj) {
                    if (!checked[nxt]) {
                        checked[nxt] = true;
                        numChecked++;
                        pos.push_back(nxt);
                    }
                }
            }
            if (numChecked < M.size()) {
                for (int i=0; i<checked.size(); ++i) {
                    if (!checked[i]) {
                        checked[i] = true;
                        pos.push_back(i);
                        numChecked++;
                        numClusters++;
                        break;
                    }
                }
                
            }
        }
       
        return numClusters;
    }
};