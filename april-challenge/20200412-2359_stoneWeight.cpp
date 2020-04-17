class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // priority queue, max
        // while queue size > 1
        // get x, get y
        // if x == y
        //   skip
        // else
        //   if x > y: 
        //      queue.add(x-y);
        //   else
        //      queue.add(y-x);
        
        priority_queue<int> q;
        for (int stone: stones)
            q.push(stone);
        
        while (q.size() > 1) {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if (x != y) {
                if (x < y) {
                    q.push(y - x);
                } else {
                    q.push(x - y);
                }
            }
        }
        
        if (q.size() > 0) {
            return q.top();
        } else {
            return 0;
        }
    }
};