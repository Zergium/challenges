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

        vector<string> result;
        addParenhesis(result, "", n, 0);
        return result;
        
    }
    
    void addParenhesis(vector<string>& result, const string& curr, int left, int right) {
        if (left == 0 && right == 0) {
            result.push_back(curr);
        } else {
            if (left > 0) {
                addParenhesis(result, curr + "(", left-1, right+1);
            }
            if (right > 0) {
                addParenhesis(result, curr + ")", left, right-1);
            }
        }
    }
};