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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        
        ListNode* pOddHead(nullptr);
        ListNode* pOdd(nullptr);
        ListNode* pEvenHead(nullptr);
        ListNode* pEven(nullptr);
        
        ListNode* pIter = head;
        bool bOdd = true;
        
        while (pIter != nullptr) {

            ListNode ** pHead;
            ListNode ** pLast;
            if (bOdd) {
                pHead = &pOddHead;
                pLast = &pOdd;
            } else {
                pHead = &pEvenHead;
                pLast = &pEven;
            }
            
            if (nullptr == *pHead) {
                *pLast = *pHead = pIter;
            } else {
                (*pLast)->next = pIter;
                *pLast = pIter;
            }
            
            bOdd = !bOdd;
            pIter = pIter->next;
        }
        
        if (pOdd != nullptr)
            pOdd->next = pEvenHead;
        if (pEven != nullptr)
            pEven->next = nullptr;
        
        return pOddHead;
    }
};