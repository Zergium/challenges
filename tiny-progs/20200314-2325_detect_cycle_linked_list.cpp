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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        ListNode* p1 = head;
        nodes.insert(p1);
        while (p1 != nullptr) {
            p1 = p1->next;
            if (nullptr != p1) {
                if (nodes.end() != nodes.find(p1)) {
                    return p1;
                }
                nodes.insert(p1);
            }
        }
        
        // ListNode* p1 = head;
        // ListNode* p2 = head;
        // while (p1 != nullptr && p2 != nullptr) {
        //     p2 = p2->next;
        //     if (nullptr != p2) {
        //         if (p2 == p1) return p1;
        //         p2 = p2->next;
        //         if (p2 == p1) return p1;
        //         p1 = p1->next;
        //     };
        // }
        return nullptr;
    }
};