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
    ListNode* mergeLists(ListNode* one, ListNode* two){
        if(!one) return two;
        if(!two) return one;

        ListNode* tempOne = one;
        ListNode* tempTwo = two;

        ListNode* anch = new ListNode(-1);
        ListNode* temp = anch;

        while(tempOne and tempTwo){
            if(tempOne->val < tempTwo->val){
                anch->next = tempOne;
                tempOne = tempOne->next;
            }else{
                anch->next = tempTwo;
                tempTwo = tempTwo->next;
            }
            anch = anch->next;
        }

        if(tempOne){
            anch->next = tempOne;
        }
        if(tempTwo){
            anch->next = tempTwo;
        }
        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;

        // Merge lists in pairs, doubling the interval each round
        int interval = 1;
        while (interval < n) {
            for (int i = 0; i + interval < n; i += interval * 2) {
                lists[i] = mergeLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }

        return lists[0];
    }
};
