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
    bool isValidFrom(TreeNode* node, vector<int>& arr, int idx) {
        if (idx >= arr.size()) {
            return node == nullptr;
        }
        if (node == nullptr) return false;
        if (node->val != arr[idx]) return false;
        
        if (idx == arr.size()-1) {
            return node->left == nullptr && node->right == nullptr;
        }
        
        return isValidFrom(node->left, arr, idx+1) || isValidFrom(node->right, arr, idx+1);
        
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return isValidFrom(root, arr, 0);
    }
};