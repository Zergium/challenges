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
    ListNode* revert(ListNode* N) {
        ListNode* current = N;
        ListNode* prev = nullptr;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    
    string to_str(ListNode* N) {
        stringstream ss;
        ss << "(";
        while (N != nullptr) {
            ss << N->val;
            if (N->next != nullptr) ss << " -> ";
            N = N->next;
        }
        ss << ")";
        return ss.str();
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1p = revert(l1);
        ListNode* l2p = revert(l2);
        ListNode* add1 = l1p;
        ListNode* add2 = l2p;
        ListNode dummy;
        ListNode* res = &dummy;
        // cout << "add1: " << to_str(add1) << endl;
        // cout << "add2: " << to_str(add2) << endl;
        int pastDigit = 0;
        while (nullptr != add1 || nullptr != add2) {
            // cout << "---- iter ----" << endl;
            // cout << "add1: " << to_str(add1) << endl;
            // cout << "add2: " << to_str(add2) << endl;
            int val1(0);
            if (add1 != nullptr) {
                val1 = add1->val;
                add1 = add1->next;
            }
            int val2(0);
            if (add2 != nullptr) {
                val2 = add2->val;
                add2 = add2->next;
            }

//            cout << "  adding " << val1 << " + " << val2 << " + " << pastDigit;
            int sum = val1 + val2 + pastDigit;
            int digit = sum % 10;
            pastDigit = sum / 10;
//            cout << " sum = " << sum << ";   digit " << digit << " and postDigit " << pastDigit << endl;
            res->next = new ListNode(digit);
            res = res->next;
        }

        if (pastDigit > 0)
            res->next = new ListNode(pastDigit);
        
        ListNode* result = revert(dummy.next);
        return result;
    }
};