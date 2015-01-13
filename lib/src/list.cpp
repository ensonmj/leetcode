#include <iostream>
#include "list.h"

using namespace std;

ListNode *mkList(const char *str) {
    ListNode *head=nullptr, *p=nullptr;
    const char *begin = str;
    char *end;
    for(int val = strtol(begin, &end, 10); begin != end;
            val = strtol(begin, &end, 10)) {
        begin = end + 1;
        ListNode *node = new ListNode(val);
        if(!head) {
            p = head = node;
        } else {
            p->next = node;
            p = node;
        }

        if(*end == '\0') {
            break;
        }
    }

    return head;
}

void destroyList(ListNode *head) {
    while(head) {
        ListNode *p = head;
        head = head->next;
        delete p;
    }
}

void printList(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
