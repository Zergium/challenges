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
    bool isNodeInRange(TreeNode* node, 
                       bool is_min_limit, int min_limit, 
                       bool is_max_limit, int max_limit) {
        //cout << (nullptr != node ? node->val : -11111) << "; min " << min_val << "; max " << max_val << endl;
        if (nullptr == node) return true;
        if (is_min_limit && min_limit >= node->val) return false;
        if (is_max_limit && node->val >= max_limit) return false;
        return isNodeInRange(node->left, is_min_limit, min_limit, true, node->val) && 
            isNodeInRange(node->right, true, node->val, is_max_limit, max_limit);
    }
    bool isValidBST(TreeNode* root) {
        bool result = isNodeInRange(root, false, 0, false, 0);
        return result;
    }
};