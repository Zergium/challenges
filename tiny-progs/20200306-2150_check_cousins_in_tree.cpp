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
    pair<int, TreeNode*> getDepth(TreeNode* node, int nodeLevel, TreeNode* parentNode, int value) {
        if (nullptr != node) {
            if (node->val == value) {
                return {nodeLevel, parentNode};
            }
            pair<int, TreeNode*> result = getDepth(node->left, nodeLevel+1, node, value);
            if (result.first < 0) {
                result = getDepth(node->right, nodeLevel+1, node, value);
            }
            return result;
        }
        return {-1, nullptr};
    }
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> xRes = getDepth(root, 0, nullptr, x);
        pair<int, TreeNode*> yRes = getDepth(root, 0, nullptr, y);
        bool result = xRes.first == yRes.first && // same level
            xRes.second != yRes.second; // different parents
        return result;
    }
};