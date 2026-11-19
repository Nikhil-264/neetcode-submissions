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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> vals;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];

            ListNode* temp = head;
            while(temp){
                vals.push_back(temp->val);
                temp = temp->next;
            }
        }
        sort(vals.begin(), vals.end());
        int n = vals.size();

        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        for(int num : vals){
            temp->next = new ListNode(num);
            temp = temp->next;
        }
        return head->next;
    }
};
