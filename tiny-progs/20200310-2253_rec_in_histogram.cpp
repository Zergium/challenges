class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        deque<int> stack_idx;
        int idx = 0;
        int max_area = 0;
        while (idx < heights.size()) {
            int h = heights[idx];
            // cout << "idx " << idx << ",  h = " << h << endl;
            if (stack_idx.empty()) {
                stack_idx.push_back(idx);
            } else {
                while (!stack_idx.empty() && heights[stack_idx.back()] > h) {
                    int prev_idx = stack_idx.back();
                    stack_idx.pop_back();
                    
                    int prev_h = heights[prev_idx];
                    int area;
                    if (stack_idx.empty()) {
                        area = prev_h * idx;
                    } else {
                        area = prev_h * (idx - stack_idx.back() - 1);
                    }
                    // cout << "   area " << area << ";  prev_h " << prev_h << ", idx " << idx << ", prev_idx " << prev_idx <<endl;
                    max_area = max(area, max_area);
                }
                stack_idx.push_back(idx);
            }
            idx++;
        }

        // cout << "--- done walk - check stack" << endl;
        
        while (!stack_idx.empty()) {
            int prev_idx = stack_idx.back();
            stack_idx.pop_back();

            int prev_h = heights[prev_idx];
            int area;
            if (stack_idx.empty()) {
                area = prev_h * idx;
            } else {
                area = prev_h * (idx - stack_idx.back() - 1);
            }
            // cout << "   area " << area << endl;
            max_area = max(area, max_area);
        }
        
        return max_area;

    }
};