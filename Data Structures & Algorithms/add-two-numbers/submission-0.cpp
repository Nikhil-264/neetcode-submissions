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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1 = reverseList(l1);
        // l2 = reverseList(l2);

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        ListNode* list1 = l1;
        ListNode* list2 = l2;

        int carry = 0;

        while(l1 or l2){
            int num1 = 0;
            int num2 = 0;

            if(l1) num1 = l1->val;
            if(l2) num2 = l2->val;

            int num = num1 + num2 + carry;
            int rem = num % 10;

            carry = num / 10;
            temp->next = new ListNode(rem);

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            temp = temp->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
            carry = 0;
        }

        temp = head->next;
        // temp = reverseList(temp);
        return temp;
        
    }
};
