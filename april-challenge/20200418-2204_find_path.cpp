class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int rows = grid.size();
        if (rows < 1) return 0;
        const int cols = grid[0].size();
        if (cols < 1) return 0;
        
        vector<vector<int>> price(rows, vector<int>(cols, -1));
        
        typedef pair<int,int> pos_t;
        queue<pos_t> q;
        
        q.push({0,0});
        price[0][0] = grid[0][0];
        
        while (!q.empty()) {
            auto [row,col] = q.front(); 
            q.pop();
            
            auto fn_probe = [&](int row, int col, int prev_steps) {
                int& cur_price(price[row][col]);
                int this_step(grid[row][col]);
                if (cur_price == -1 || cur_price > prev_steps + this_step) {
                    cur_price = prev_steps + this_step;
                    q.push({row,col});
                }
            };
            
            int this_price(price[row][col]);
            if (row+1 < rows) fn_probe(row+1, col, this_price);
            //if (row-1 >= 0) fn_probe(row-1, col, this_price);
            if (col+1 < cols) fn_probe(row, col+1, this_price);
            //if (col-1 >= 0) fn_probe(row, col-1, this_price);
        }
        

        vector<vector<int>> path(rows, vector<int>(cols, 0));
        q.push({rows-1,cols-1});
        int step = 1;
        path[rows-1][cols-1] = step++;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            auto fn_check=[&](int r, int c, int expected, int step) {
                if (expected == price[r][c] && path[r][c] == 0) {
                    q.push({r,c});
                    path[r][c] = step;
                };
            };
            int expected = price[row][col] - grid[row][col];
            //cout << "check " << row << ", " << col << ", exp  = " << expected << endl;
            if (row+1 < rows) fn_check(row+1, col, expected, step);
            if (row-1 >= 0) fn_check(row-1, col, expected, step);
            if (col+1 < cols) fn_check(row, col+1, expected, step);
            if (col-1 >= 0) fn_check(row, col-1, expected, step);
            step++;
        }
       
        // for (auto r: grid) {
        //     for (auto p: r) {
        //         cout << p << ",";
        //     }
        //     cout << endl;
        // }
        // cout << "-----" << endl;
        // for (auto r: path) {
        //     for (auto p: r) {
        //         cout << p << ",";
        //     }
        //     cout << endl;
        // }
        // cout << "-----" << endl;
        // for (auto r: price) {
        //     for (auto p: r) {
        //         cout << p << ",";
        //     }
        //     cout << endl;
        // }
        // cout << "-----" << endl;
        // for (int r = 0; r < rows; r++) {
        //     for (int c = 0; c< cols; c++) {
        //         if (path[r][c] > 0) {
        //             cout << grid[r][c];
        //         }
        //         cout << ",";
        //     }
        //     cout << endl;
        // }
        
        return price[rows-1][cols-1];
    }
};