/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* root = head;
        ListNode* next = root;
        if (next != nullptr) {
            next = next->next;
            root->next = nullptr;
        }
        
        while (nullptr != next) {
            ListNode* new_next = next->next;
            next->next = root;
            root = next;
            next = new_next;
        }
        return root;
    }
};