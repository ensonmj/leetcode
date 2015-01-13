#ifndef __LIB_LIST__
#define __LIB_LIST__

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *p=nullptr) : val(x), next(p) {}
};

ListNode *mkList(const char *str);
void destroyList(ListNode *head);
void printList(ListNode *head);

#endif
