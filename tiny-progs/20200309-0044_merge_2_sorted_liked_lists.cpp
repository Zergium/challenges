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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result(nullptr);
        ListNode* current(nullptr);
        while (l1 != nullptr && l2 != nullptr) {
            ListNode** picked;
            if (l1->val < l2->val) {
                picked = &l1;
            } else {
                picked = &l2;
            }
            if (nullptr == current) {
                current = *picked;
                result = current;
            } else {
                current->next = *picked;
                current = current->next;
            }
            *picked = (*picked)->next;
        }
        
        if (nullptr != l1) {
            if (current != nullptr)
                current->next = l1;
            else 
                result = l1;
        }
        if (nullptr != l2) {
            if (current != nullptr)
                current->next = l2;
            else
                result = l2;
            
        }
        return result;
    }
};