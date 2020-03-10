class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int, int> amounts;
        for (int candy: candies) {
            amounts[candy] += 1;
        }
        return min(amounts.size(), candies.size()/2);;
    }
};


///////////////// alternative is

static auto __ __attribute__((unused)) = []() {  // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    int distributeCandies(vector<int>& v) {
        bitset<200001> kinds;
        
        for (auto c: v) {
            //kinds.insert(c);
            kinds.set(c + 100000);
        }
        
        return min(kinds.count(), v.size() / 2);
    }
};