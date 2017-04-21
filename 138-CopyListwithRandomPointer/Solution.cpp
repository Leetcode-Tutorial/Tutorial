class Solution {
public:
    unordered_map<RandomListNode*, RandomListNode*> ma;
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        auto newnode = new RandomListNode(head->label);
        ma[head] = newnode;//put in a hashmap
        newnode->next = copyRandomList(head->next);//create the list
        newnode->random = ma[head->random];//deepcopy random pointer
        return newnode;
    }
};
