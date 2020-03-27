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
    vector<int> inorderTraversal(TreeNode* root) {
        if (nullptr == root) return {};

        vector<int> result;
        deque<pair<TreeNode*, bool>> q;
        q.push_back({root, false});
        while (!q.empty()) {
            pair<TreeNode*, bool> item = q.front();
            q.pop_front();
            
            TreeNode* node(item.first);
            if (item.second) {
                result.push_back(node->val);
            } else {
                if (nullptr != node->right) {
                    q.push_front({node->right, false});
                }
                q.push_front({node, true});
                if (nullptr != node->left) {
                    q.push_front({node->left, false});
                }
            }
        }
        
        return result;
    }
};