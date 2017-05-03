class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
		ListNode *p = head, *q;
        int len = 1;
        while(p->next) {
            len++;
            p = p->next;
        }
        if(!(k %= len)) return head;//if k%len == 0, needn't do anything
        k = len-k;
		p->next = head;//let the last node point to head
		while(k--)
			p = p->next;//find the kth node
		head = p->next;
		p->next = NULL;//break the list
		return head;
    }
};
