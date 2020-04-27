
/// basic maximal square
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if (h<1) return 0;
        int w = matrix[0].size();
        if (w<1) return 0;
        int best_amount = 0;
        for (int x=0; x<w; x++) {
            for (int y=0; y<h; y++) {
                for (int sx = 1; sx <= w-x; sx++) {
                    for (int sy = 1; sy <= h-y; sy++) {
                        if (
                            sx != sy || 
                            sx * sy <= best_amount) continue;
                        
                        bool ones = true;
                        for (int i=0; i<sx && ones; i++) {
                            for (int j=0; j<sy; j++) {
                                if (matrix[y+j][x+i] != '1') {
                                    ones = false;
                                    break;
                                }
                            }
                        }
                        if (ones) {
                            if (best_amount < sx*sy) {
                                best_amount = sx*sy;
                            }
                        }
                    }
                }
            }
        }
        return best_amount;
    }
};

