class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n(points.size());
        if (n<3) {
          return n;  
        }
        int maxPoints = 2;
        for (int i = 0; i < n-2; ++i)
            for (int j = i + 1; j < n-1; ++j) {
                int numPoints = 2;
                int dj_x = points[i][0]-points[j][0];
                int dj_y = points[i][1]-points[j][1];
                
                for (int k = j + 1; k < n; ++k) {
                    int dk_x = points[i][0]-points[j][0];
                    int dk_y = points[i][1]-points[j][1];
                    
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
                        numPoints++;
                    }
                }
                
                if (maxPoints < numPoints) 
                    maxPoints = numPoints;
            }
        return maxPoints;
    }
};