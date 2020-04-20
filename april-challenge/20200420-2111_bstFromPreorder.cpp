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
    
    int fillNode(TreeNode* node, const vector<int>& preorder, int idx, bool has_max, int max_val) {
        int val = preorder[idx];
        node->val = val;
        idx++;
        if (idx < preorder.size()) {
            if (preorder[idx] < val) {
                node->left = new TreeNode();
                idx = fillNode(node->left, preorder, idx, true, val);
            };
            
            if (idx < preorder.size()) {
                if (!has_max || preorder[idx] < max_val) {
                    node->right = new TreeNode();
                    idx = fillNode(node->right, preorder, idx, has_max, max_val);
                }
            }
        }
        return idx;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() < 1) return nullptr;
        
        TreeNode* root = new TreeNode();
        
        fillNode(root, preorder, 0, false, 0);
        
        return root;
        
    }
};