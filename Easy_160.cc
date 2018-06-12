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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        ListNode *pa = headA;
        ListNode *pb = headB;
        
        while(pa != pb)
        {
            pa = !pa? headB : pa->next;
            pb = !pb? headA : pb->next;
        }
        return pa;
    }
};