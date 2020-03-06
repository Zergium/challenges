// trick is that some coordinates are toooo large and there are duplicated points

class Solution {
public:
    int maxPoints(vector<vector<int>>& points_org) {
        vector<vector<int>> points;
        for (auto& pnt: points_org) {
            bool found(false);
            for (auto& existing: points) {
                if (pnt[0] == existing[0] && pnt[1] == existing[1]) {
                    found = true;
                    existing[2]++;
                    break;
                }
            }
            if (!found) {
                points.push_back({pnt[0], pnt[1], 1});
            }
        }
        
        /// now points has [x, y, num_at_this_point] without duplicates of [x,y]
                  
        int n(points.size());
        if (n<3) {
            int result(0);
            for (auto pnt: points) {
                result += pnt[2];
            }
            return result;
        }
        int maxPoints = 2;
        for (int i = 0; i < n-2; ++i)
            for (int j = i + 1; j < n-1; ++j) {
                int numPoints = points[i][2] + points[j][2];
                long long dj_x = points[i][0]-points[j][0];
                long long dj_y = points[i][1]-points[j][1];
                
                for (int k = j + 1; k < n; ++k) {
                    long long dk_x = points[i][0]-points[k][0];
                    long long dk_y = points[i][1]-points[k][1];
                    
                    bool sameLine = false;
                    if (dj_x == 0) {
                        if (dk_x == 0) {
                            sameLine = true;
                        }
                    } else if (dk_x == 0) {
                        // already: sameLine = false; // dj_x was not 0 → not on same line 
                    } else {
                        if (dj_y * dk_x == dk_y * dj_x) {
                            sameLine = true;
                        }
                    }
                    if (sameLine) {
                        numPoints += points[k][2];
                    }
                }
                
                if (maxPoints < numPoints) 
                    maxPoints = numPoints;
            }
        return maxPoints;
    }
};