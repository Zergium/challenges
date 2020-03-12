class Solution {
public:
    int totalFruit(vector<int>& tree) {
        struct counter_t {
            int num;
            int prev_num;
            int fruit;
            counter_t(int a_fruit, int a_num=1)
                :fruit(a_fruit), num(a_num), prev_num(0) {};
            string tostring() {
                stringstream ss;
                ss << "(" << fruit << ", num = " << num << ", "<< prev_num <<" prev)";
                return ss.str();
            };
            int getnum() { return num + prev_num; };
        };
        
        counter_t a(-1,0);
        counter_t b(-1,0);
        
        int max = 0;
        int max_idx = -1;
        
        for (int i=0; i<tree.size(); ++i) {
            int fruit = tree[i];
            if (a.fruit == fruit) {
                a.num++;
                //cout << "inc " << fruit << "; ";
            } else if (b.fruit == fruit) {
                swap(a, b);
                a.prev_num += a.num;
                a.num = 1;
                //cout << "swap for " << fruit << "; ";
            } else {
                b = a;
                b.prev_num = 0;
                a = counter_t(fruit, 1);
                //cout << "new " << fruit << "; ";
            }
            
            
            int sum = a.getnum() + b.getnum();
            //cout << "sum " << sum << ", of "<< a.tostring() << " and " << b.tostring() << endl;

            if (max < sum) {
                max_idx = i;
                max = sum;
               // cout << "yet another max " << max << " at " << max_idx << endl;
            } else {
                //cout << "skip sum = " << sum << endl;
            }
            
        }
        
        return max;
    }
};
// [1,0,1,4,1,4,1,2,3]
// [3,3,3,1,2,1,1,2,3,3,4] -> 5