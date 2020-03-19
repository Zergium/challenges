class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<int> order(indexes.size(), 0);
        for (int i = 0; i < order.size(); i++) {
            order[i] = i;
        }
        // cout << "order before: ";
        // for (auto o: order) cout << o << "; ";
        // cout << endl;
        sort(order.begin(), order.end(), [&](int i,int j) {return indexes[i] > indexes[j];});
        // cout << "order sorted: ";
        // for (auto o: order) cout << o << "; ";
        // cout << endl;
        for (int o = 0; o < order.size(); o++) {
            int i = order[o];
            //cout << "i: " << i << "; S: " << S << endl;
            int index = indexes[i];
            string& src = sources[i];
            int src_size = src.length();
            string& trg = targets[i];
            if (S.substr(index, src_size) == src) {
                S.replace(index, src_size, trg);
            }
        }
        return S;
    }
};