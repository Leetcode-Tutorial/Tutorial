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
    void inv(ListNode *&start, ListNode *&end){//reverse the node from start to end
        ListNode *p = start, *m = p->next, *q = m->next;
        start->next = end->next;
        while(m != end){
            m->next = p;
            p = m;
            m = q;
            q = q->next;
        }
        m->next = p;
        swap(start, end);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k < 2) return head;
        ListNode *p1 = head, *p2 = NULL;
        for(int i = 1; i < k&&p1 != NULL; i++) p1 = p1->next;//go k steps
        if(p1 == NULL) return head;//return the node if there's not enough nodes
        p2 = p1->next;
        inv(head, p1);//reverse the list from head to p1
        while(true){
            p2 = p1->next;
            for(int i = 1; i < k&&p2 != NULL; i++) p2 = p2->next;//go k steps
            if(p2 == NULL) return head;//return the node if there's not enough nodes
            inv(p1->next, p2);
            p1 = p2;
        }
    }
};
