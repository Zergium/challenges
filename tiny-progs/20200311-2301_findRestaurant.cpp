class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map1;
        for (int i=0; i<list1.size(); ++i) {
            map1[list1[i]] = i;
        }
        
        int minInterest = numeric_limits<int>::max();
        vector<pair<int,string>> vecSumPlace;
        for (int i=0; i<list2.size(); ++i) {
            auto it = map1.find(list2[i]);
            if (it != map1.end()) {
                int interest = i+it->second;
                vecSumPlace.push_back({interest, list2[i]});
                
                minInterest = min(minInterest, interest);
            }
        }
        
        vector<string> result;
        if (minInterest < numeric_limits<int>::max()) {
            for (auto& item: vecSumPlace) {
                if (item.first == minInterest) {
                    result.push_back(item.second);
                }
            }
        }
        
        return result;
        
    }
};