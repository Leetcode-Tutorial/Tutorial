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
    struct node {
        int val, id;
        bool operator < (const node & _) const {
            return val > _.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <node>que;
        while (!que.empty ()) que.pop ();
        int n = lists.size ();
        ListNode *head = new ListNode (0), *p; p = head;
        
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                que.push ((node) {lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        
        while (!que.empty ()) {
            node tmp = que.top (); que.pop ();
            if (lists[tmp.id] != NULL) {
                que.push ((node) {lists[tmp.id]->val, tmp.id});
                lists[tmp.id] = lists[tmp.id]->next;
            }
            p->next = new ListNode (tmp.val);
            p = p->next;
        }
        return head->next;
    }
};
