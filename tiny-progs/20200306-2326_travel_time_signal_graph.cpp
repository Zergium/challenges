class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        struct node_t {
            vector<vector<int>> adjWeight;
        };
        vector<node_t> graph(N);
        for (auto edge: times) {
            graph[edge[0]-1].adjWeight.push_back({edge[1]-1, edge[2]});
        }
        
        vector<int> bestTime(N, -1);
        bestTime[K-1] = 0;
        std::deque<int> nodes;
        nodes.push_back(K-1);
        while (!nodes.empty()) {
            int curr = nodes.front();
            nodes.pop_front();
            for (auto next: graph[curr].adjWeight) {
                int link = next[0];
                int weight = next[1];
                if (bestTime[link] < 0 ||
                    bestTime[link] > bestTime[curr] + weight) {
                    bestTime[link] = bestTime[curr] + weight;
                    nodes.push_back(link);
                }
            }
        }
        
        int maxDelay = bestTime[0];
        for (int delay: bestTime) {
            if (delay < 0) return -1;
            if (maxDelay < delay) maxDelay = delay;
        }
        return maxDelay;
    }
};