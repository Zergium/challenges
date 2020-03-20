class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        int h = grid.size();
        if (h<1) return 0;
        int w = grid[0].size();
        if (w<1) return 0;
        cout << "h " << h << "; w " << w << endl;
        for (int j=0; j<h; j++) {
            for (int i=0; i<w; i++) {
                cout << "grid[" << j << "][" << i << "] == " << grid[j][i] << endl;

                if (grid[j][i] == 1) {
                    counter++;
                    cout << "inc counter, counter = " << counter << endl;
                    
                    deque<pair<int,int>> q;
                    auto fn_add = [&](int j, int i) {
                        if (j >= 0 && j<h && i >= 0 && i < w) {
                            if (grid[j][i] == 1) {
                                grid[j][i] = 2; // mark visited
                                q.push_back({j,i});
                            }
                        }    
                    };                    
                    fn_add(j,i);
                    while (!q.empty()) {
                        pair<int,int> pos = q.front();
                        q.pop_front();
                        int try_j = pos.first;
                        int try_i = pos.second;
                        // asert (grid[try_j][try_i] == 1)
                        grid[try_j][try_i] = 2; // 2 = visited

                        for (int d=-1;d<2; d+=2) {
                            fn_add(try_j+d,try_i);
                            fn_add(try_j,try_i+d);
                        }
                    }
                }
            }
        }
        return counter;
    }
};