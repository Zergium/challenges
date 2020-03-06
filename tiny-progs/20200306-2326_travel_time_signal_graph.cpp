class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<int> bestTime(N, -1);
        bestTime[K-1] = 0;
        std::deque<int> nodes;
        nodes.push_back(K-1);
        while (!nodes.empty()) {
            int curr = nodes.front();
            nodes.pop_front();
            for (auto edge: times) {
                if (edge[0]-1 == curr) {
                    int link = edge[1]-1;
                    int weight = edge[2];
                    if (bestTime[link] < 0 ||
                        bestTime[link] > bestTime[curr] + weight) {
                        bestTime[link] = bestTime[curr] + weight;
                        nodes.push_back(link);
                    }
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