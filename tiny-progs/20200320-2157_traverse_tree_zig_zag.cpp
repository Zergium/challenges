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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) return {};
        vector<vector<int>> result;
        deque<TreeNode*> current_level;
        deque<TreeNode*> next_level;
        current_level.push_back(root);
        int level_no = 0;
        while (!current_level.empty()) {
//             cout << "---" << endl;
//             for (auto x: current_level) {
//                 cout << x->val << "; ";
//             }
//             cout << endl;
            
            vector<int> level_node_values;
            while (!current_level.empty()) {
                TreeNode* node = current_level.front();
                current_level.pop_front();
                level_node_values.push_back(node->val);
                auto fn_add_node = [&](TreeNode* node) {
                    if (node != nullptr) {
                        next_level.push_back(node);
                    }
                };
                fn_add_node(node->left);
                fn_add_node(node->right);
            }
            if (level_no % 2 == 1) {
                reverse(level_node_values.begin(), level_node_values.end());
            }
            level_no++;
            result.push_back(level_node_values);
            current_level = next_level;
            next_level.clear();
        }
        return result;
    }
};