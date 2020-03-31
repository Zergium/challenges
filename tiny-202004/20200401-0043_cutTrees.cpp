// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:


// You are asked to cut off trees in a forest for a golf event. The forest is represented as a non-negative 2D map, in this map:


class Solution {
public:
    
    struct pos_t {
        pos_t(int ax, int ay)
            :x(ax), y(ay) {};
        bool operator==(const pos_t& other) {
            return other.x == x && other.y == y;
        };
        string str() const {
            stringstream ss;
            ss << "(" << x << "," << y << ")";
            return ss.str();
        };
        int x;
        int y;
    };
        
    class graph_t {
    public:
        graph_t(vector<vector<int>>& a_forest) 
        : forest(a_forest)
        , visited(a_forest) {
            h = forest.size();
            w = 0;
            if (h > 0) w = forest[0].size();
            clear_visited();
        }
        const int forest_at(const pos_t& p) {
            return forest[p.y][p.x];
        }
        int& visit_at(const pos_t& p) {
            return visited[p.y][p.x];
        }
        void clear_visited() {
            for (auto& row: visited) {
                fill(row.begin(), row.end(), -1);
            }
        }
        bool is_pos_valid(const pos_t& p) {
            return p.x >= 0 && p.x < w && p.y >= 0 && p.y < h;
        }
        vector<vector<int>> forest;
        vector<vector<int>> visited;
        int w; // width
        int h; // height
    };
    
    
    int getDistance(pos_t& a, pos_t& b, graph_t& g) {
        //cout << "distance from " << a.str() << " to " << b.str() << endl;
        if (a == b) { return 0; }

        // bfs
        g.clear_visited();
        queue<pos_t> q;
        q.push(a);
        g.visit_at(a) = 0;
        while (!q.empty()) {
            pos_t cur = q.front(); q.pop();
            int cur_step = g.visit_at(cur);
            if (cur == b) {
                return cur_step;
            }

            auto fn_check_pos = [&](const pos_t& new_pos) {
                //cout << "  new_pos" << new_pos.str() << endl;
                if (g.is_pos_valid(new_pos) && g.forest_at(new_pos) != 0) {
                    int& visit = g.visit_at(new_pos);
                    if (visit == -1) {
                        visit = cur_step + 1;
                        q.push(new_pos);
                    }
                }
            };
            for (int dd = -1; dd <= 1; dd += 2) {
                fn_check_pos(pos_t(cur.x + dd, cur.y));                
                fn_check_pos(pos_t(cur.x, cur.y + dd));                
            }
            
        }
        return -1; // we didn't reach the target pos
    }
    
    int cutOffTree(vector<vector<int>>& forest) {
        // 50 * 50 = 2500 * 2500 = 4000000
        
        // walk through forest collect (height -> pos)
        struct tree_t {
          tree_t(int aheight, pos_t apos)
              : height(aheight), pos(apos) {}
            int height;
            pos_t pos;
        };
        
        graph_t g(forest);
        vector<tree_t> trees;
        for (int j=0; j<g.h; j++) {
            for (int i=0; i<g.w; i++) {
                pos_t p(i,j);
                int height = g.forest_at(p);
                if (height > 1) {
                    trees.push_back({height, p});
                }
            }
        }
        

        sort(trees.begin(), trees.end(), [](tree_t& a, tree_t& b) { return a.height < b.height; });
        
        int sum(0);
        
        pos_t cur(0,0);
        for (int idx = 0; idx < trees.size(); idx++) {
            pos_t trg = trees[idx].pos;
            int step = getDistance(cur, trg, g);
            if (step < 0) {
                return -1;
            }
            sum += step;
            cur = trg;
        }

        
        return sum;
    }
};




/*

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int res = 0, m = forest.size(), n = forest[0].size(), cur = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (forest[i][j] > 1) pq.push(forest[i][j]);
        
        int dirs[][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty())
        {
            int target = pq.top(); pq.pop();
            int cnt = -1;
            bool found = false;
            queue<int> q{{cur}};
            vector<int> visited(m * n, false); visited[cur] = true;  // using unordered_set is slow
            
            // bfs search
            while(!q.empty())
            {
                int qs = q.size();
                ++cnt;
                while(qs--)
                {
                    int curtop = q.front(); q.pop();
                    int curx = curtop / n, cury = curtop % n;
                    if (forest[curx][cury] == target) {found = true; cur = curtop; break;}
                    for (const auto & d: dirs)
                    {
                        int x = curx + d[0];
                        int y = cury + d[1];
                        int pos = x * n + y;
                        if (x<0 || x>=m || y<0 || y>=n || visited[pos] || forest[x][y] == 0) continue;
                        visited[pos] = true;
                        q.push(pos);
                    }
                }
                if (found) break;
            }
            
            if (!found) return -1;
            res += cnt;
        }
        return res;
    }
};

*/