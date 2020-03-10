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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        deque<pair<TreeNode*, TreeNode*>> nodes_to_compare;
        nodes_to_compare.push_back({p,q});

        while (!nodes_to_compare.empty()) {
            auto compare = nodes_to_compare.front();
            nodes_to_compare.pop_front();
            TreeNode* pp = compare.first;
            TreeNode* qq = compare.second;

            if (pp == nullptr) {
                if (qq != nullptr) {
                    return false;
                }
            } else {
                if (qq == nullptr) {
                    return false;
                };
                
                if (pp->val != qq->val) return false;
                nodes_to_compare.push_back({pp->left, qq->left});
                nodes_to_compare.push_back({pp->right, qq->right});
            }
        };
        return true;
    }
};