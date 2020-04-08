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
    ListNode* middleNode(ListNode* head) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        while (p2 != nullptr) {
            p2 = p2->next;
            if (p2 != nullptr) {
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        return p1;
    }
};