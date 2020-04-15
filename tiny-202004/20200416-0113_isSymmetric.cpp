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
public:
    bool isSame(TreeNode* left, TreeNode* right) {
        if (nullptr == left && nullptr == right) return true;
        if (nullptr == left || nullptr == right) return false;
        if (left->val != right->val) return false;
        
        return isSame(left->left, right->right) && isSame(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (nullptr == root) return true;
        return isSame(root->left, root->right);
    }
};