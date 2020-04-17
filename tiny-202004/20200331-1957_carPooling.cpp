class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        typedef pair<int,int> step_t;
        vector<step_t> steps;
        // fillup the steps <pos, +-pass)
        for (int i = 0; i<trips.size(); i++) {
            vector<int>& trip = trips[i];
            steps.push_back({trip[1],trip[0]});
            steps.push_back({trip[2],-trip[0]});
        }
        
        sort(steps.begin(), steps.end(), [](step_t& a, step_t& b) {
            return a.first < b.first; 
        });
        
        // cout << "---" << endl;
        // for (auto t : steps) {
        //     cout << "(" << t.first << ", " << t.second << ") - ";
        // }
        // cout << endl;
        
        int passengers = 0;
        
        for (int idx = 0; idx < steps.size(); idx++) {
            step_t& step = steps[idx];
            int pos = step.first;
           
            passengers += step.second;
            if (idx < steps.size()-1) {
                if (step.first == steps[idx+1].first) {
                    continue;
                }
            }
            if (passengers > capacity) return false;
        }
        
        return true;
        
    }
};