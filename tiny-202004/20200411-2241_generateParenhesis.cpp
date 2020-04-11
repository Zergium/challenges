class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // n
        // n == 1
        // ()
        // 
        // n > 1
        // () %n-1%
        // ( %n-1% )
        // %n-1% ()
        
        
        // n = 1
        // ()
        // n = 2
        // ()()
        // (())
        // n = 3
        // ()()() x 2 
        // (()())
        
        // ()(())
        // (())()
        // ((()))
        // 

        if (n == 0) { return {}; }
        unordered_set<string> variants;
        variants.insert("()");
        int i = 1;
        while (i<n) {
            unordered_set<string> next;
            for (const auto& v: variants) {
                next.insert(v + "()");
                next.insert("()" + v);
                next.insert("(" + v + ")");
            }   
            i++;
            variants = move(next);
        }
        
        vector<string> result;
        for (auto& v: variants) {
            result.push_back(v);
        }
        return result;
        
    }
};