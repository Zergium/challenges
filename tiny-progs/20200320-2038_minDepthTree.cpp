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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = numeric_limits<int>::max();
        if (nullptr != root->left) {
            res = minDepth(root->left)+1;
        }
        if (nullptr != root->right) {
            res = min(res, minDepth(root->right)+1);
        };
        if (res == numeric_limits<int>::max()) {
            res = 1;
        }
        return res;
    }
};