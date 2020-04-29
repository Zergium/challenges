/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int getSum(TreeNode* node, int& best) {
        if (node == nullptr) return 0;
        int left = getSum(node->left, best);
        int right = getSum(node->right, best);
        int current = max(0, left) + node->val + max(0, right);
        best = max(best, current);
        return max(max(left, right), 0) + node->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int best(numeric_limits<int>::min());
        getSum(root, best);
        return best;
    }
    

};


