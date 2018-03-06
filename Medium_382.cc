/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* Reservoir Sampling:
   Problem: Choose k entries from n numbers. Make sure each number is selected with the probability of k/n

   Basic idea:
     Choose 1, 2, 3, ..., k first and put them into the reservoir
     For k + 1, pick it with a probability of k/(k + 1), and randomly replace a number in the reservoir
     For k + i, pick it with a probability of k/(k + i), and randomly replace a number in the reservoir
     Repeat until k + i reaches n
*/
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val;
        ListNode* node = head->next;
        int i = 2;
        while(node)
        {
            int j = rand() % i;
            if(j == 0)
                res = node->val;
            i++;
            node = node->next;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */