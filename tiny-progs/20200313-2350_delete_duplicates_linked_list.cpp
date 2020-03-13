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
        unordered_map<int, int> numbers;
        ListNode* walk = head;
        while (nullptr != walk) {
            numbers[walk->val]++;
            walk = walk->next;
        };
        
        ListNode dummy(0);
        dummy.next = head;
        walk = &dummy;
        while (walk->next != nullptr) {
            auto it = numbers.find(walk->next->val);
            if (it->second > 1) {
                ListNode* to_del = walk->next;
                walk->next = walk->next->next;
                delete to_del;
            } else {
                walk = walk->next;
            };
        }
        return dummy.next;
    }
};