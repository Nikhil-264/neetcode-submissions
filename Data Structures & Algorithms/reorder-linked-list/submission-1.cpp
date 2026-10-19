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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* temp = head;

        ListNode* slow = temp;
        ListNode* fast = temp;

        while(fast and fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        fast = reverseList(fast);

        slow = head;

        while(fast){
            ListNode* slowNext = slow->next;
            ListNode* fastNext = fast->next;
            slow->next = fast;
            fast->next = slowNext;
            slow = slowNext;
            fast = fastNext;
        }
        
    }
};
