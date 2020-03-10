// O(n*h)
// n - amount of has_buildings
// h - max height of a building

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int levels_above = 0;
        bool has_buildings = true;
        int max_rect = 0;
        while (has_buildings) {
            // cout << "--- loop ---" << endl;
            // for (auto h: heights) cout << h << " ";
            // cout << endl;
            
            int min_height = 0;
            int max_height = 0;
            int max_len = 0;
            int idx_start = 0;
            for (int i=0; i<heights.size(); i++) {
                if (heights[i] > 0) {
                    if (min_height == 0) {
                        min_height = heights[i];
                    } else {
                        min_height = min(min_height, heights[i]);        
                    }
                }
                
                max_height = max(max_height, heights[i]);
                if (heights[i] == 0) {
                    max_len = max(max_len, i - idx_start);
                    idx_start = i+1;
                };
            };
            
            // cout << "height min/max " << min_height << " / " << max_height << endl;
            // cout << "max len " << max_len << endl;
            
            int rect = max_len * (levels_above + 1);
            max_rect = max(rect, max_rect);
//            cout << "rect " << rect << ", max rect " << max_rect << endl;
            
            has_buildings = max_height > 1;
            
            int inc_levels_by = max(1, min_height-1);
            levels_above += inc_levels_by;
  //          cout << "inc levels by " << inc_levels_by << endl;
            for (int i=0; i<heights.size(); i++) {
                heights[i] = max(0, heights[i] - inc_levels_by);
            }
        }
        return max_rect;
    }
};