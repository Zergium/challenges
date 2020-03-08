class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // create result matrix with -1 (no value)
        // make a queue for 0s
        // scan matrix, put all 0s coords in and fill in result 0s
        // till queue is empty
        //   take item,
        //   check it's value 0,1,2, ...
        //   take 4 neighbours, check they are in range (x,y)
        //   put for each value+1 and add position to the queue
        // return matrix

        const static int NO_VALUE = -1;
        
        if (matrix.empty()) return {};
        int h = matrix.size();
        int w = matrix[0].size();
        vector<vector<int>> result(h, vector<int>(w, NO_VALUE));
        
        deque< pair<int,int> > qpos;
        
        for (int j=0; j<h; ++j) {
            for (int i=0; i<w; ++i) {
                if (matrix[j][i] == 0) {
                    qpos.push_back({i,j});
                    result[j][i] = 0;
                }
            }
        }
        
        auto fn_pos_ok= [&](int i, int j) -> bool {
            return i>=0 && j>=0 && i<w && j<h;
        };
        
        vector<pair<int,int>> neigbours = {
            {1,0},
            {0,1},
            {-1,0},
            {0,-1},
        };
        
        while (!qpos.empty()) {
            pair<int,int> pos = qpos.front();
            qpos.pop_front();
            int i = pos.first;
            int j = pos.second;
            int val = result[j][i];
            for (auto shift: neighbours) {
                int new_i = i + shift.first;
                int new_j = j + shift.second;
                if (fn_pos_ok(new_i,new_j)) {
                    if (result[new_j][new_i] == NO_VALUE) {
                        result[new_j][new_i] = val+1;
                        queue.push_back({new_i, new_j});
                    }
                }
            }
        }
        
        return result;
    }
};