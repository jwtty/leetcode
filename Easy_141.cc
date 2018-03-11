/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Algorithm:
 * Use two pointers, walker and runner.
 * walker moves step by step. runner moves two steps at time.
 * if the Linked List has a cycle walker and runner will meet at some point.
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return false;
        ListNode *walker = head , *runner = head;
        while(walker != NULL && runner != NULL && runner->next != NULL)
        {
            walker = walker->next;
            runner = runner->next->next;
            if(walker == runner)
                return true;
        }
        return false;
    }
};