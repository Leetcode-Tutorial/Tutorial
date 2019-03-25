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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode(-1);
        ListNode* p = Head;
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                p->val = l1->val;
                l1 = l1->next;
            }
            else {
                p->val = l2->val;
                l2 = l2->next; 
            }
            p->next = new ListNode(-1);
            p = p->next;
        }
        if(l1 != NULL){
            while(l1){
                p->val = l1->val;
                l1 = l1->next;
                p->next = new ListNode(-1);
                p = p->next;
            }
        }
        if(l2 != NULL){
            while(l2){
                p->val = l2->val;
                l2 = l2->next;
                p->next = new ListNode(-1);
                p = p->next;
            }
        }
        return Head;
    }
};