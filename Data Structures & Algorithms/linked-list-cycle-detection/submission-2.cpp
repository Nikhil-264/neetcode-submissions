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
    bool hasCycle(ListNode* head) {
        ListNode* hare = head;
        ListNode* tort = head;

        while(hare != NULL and hare->next != NULL){
            hare = hare->next->next;
            tort = tort->next;

            if(hare == tort){
                return true;
            }
        }
        return false;
    }
};
