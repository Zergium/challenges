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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode tmp;
        tmp.next = head;
        ListNode* checker = &tmp;
        while (checker != nullptr) {
            if (nullptr != checker->next && nullptr != checker->next->next) {
                if (checker->next->val == checker->next->next->val) {
                    int valToRemove = checker->next->val;
                    while (nullptr != checker->next && valToRemove == checker->next->val) {
                        checker->next = checker->next->next;
                    }
                } else {
                    checker = checker->next;
                }
            } else break;
        }
        return tmp.next;
    }
};