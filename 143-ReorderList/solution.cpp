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
    void reorderList(ListNode* head) {
        int len = 0;
        ListNode *p1 = head, *p2, *p3, *p4;
        while(p1) len++, p1 = p1->next;
        if(len < 3) return ;

        p1 = head, len /= 2;
        while(len--) p1 = p1->next;//p1 is the middle of the position
        //reverse the second half
        p2 = p1->next, p1->next = NULL, p3 = p2->next;
        while(p3)
            p2->next = p1, p1 = p2, p2 = p3, p3 = p3->next;
        p2->next = p1;
        //merge
        p1 = head;
        while(p1){
            p3 = p1->next, p1->next = p2, p1 = p3;
            if(!p2) break;
            p4 = p2->next, p2->next = p1, p2 = p4;
        }
        return ;
    }
};
