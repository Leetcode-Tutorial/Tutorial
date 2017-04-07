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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode (0);
        ListNode *p = head;
        int carry = 0;//进位
        while (true) {
            int tmp = l1->val+l2->val+carry; carry = tmp/10;
            p->val = tmp%10;
            l1 = l1->next; l2 = l2->next;
            if (l1 == NULL || l2 == NULL) break;
            p->next = new ListNode (0); p = p->next;
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                p->next = new ListNode (0); p = p->next;
                int tmp = l2->val+carry; carry = tmp/10;
                l2 = l2->next;
                p->val = tmp%10;
            }
        }
        else if (l2 == NULL) {
            while (l1 != NULL) {
                p->next = new ListNode (0); p = p->next;
                int tmp = l1->val+carry; carry = tmp/10;
                l1 = l1->next;
                p->val = tmp%10;
            }
        }
        if (carry) {
            p->next = new ListNode (carry);
            p = p->next;
        }
        return head;
    }
};
