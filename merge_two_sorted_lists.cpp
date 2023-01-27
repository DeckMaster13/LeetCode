/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* p0 = nullptr;
        
        if (l2->val >= l1->val) {
            p0 = l1;
            l1 = l1->next;
        } else {
            p0 = l2;    
            l2 = l2->next;            
        }
        
        ListNode* p = p0;
        while (l1 || l2) {
            if (!l1) { p->next = l2; return p0; }
            if (!l2) { p->next = l1; return p0; }

            if (l2->val >= l1->val) {
                p->next = l1;    
                l1 = l1->next;
            } else {
                p->next = l2;    
                l2 = l2->next;            
            }

            p = p->next;
        }
        return p0;
    }
};
