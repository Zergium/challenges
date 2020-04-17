/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    static int checkNodeAndReturnMaxDepth(TreeNode* node, int& longest) {
        if (nullptr == node) return 0;

        int leftDepth = checkNodeAndReturnMaxDepth(node->left, longest);
        int rightDepth = checkNodeAndReturnMaxDepth(node->right, longest);
        int length = leftDepth + rightDepth;
        if (length > longest) longest = length;
        
        return 1 + max(leftDepth, rightDepth);
    }
        
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // recursion, 
        int longest(0);
        checkNodeAndReturnMaxDepth(root, longest);
        return longest;
    }
};