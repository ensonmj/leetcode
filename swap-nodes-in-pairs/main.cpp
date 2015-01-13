#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode *p=nullptr) : val(x), next(p) {}
};

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

void print(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void destroy(ListNode *head) {
    while(head) {
        ListNode *p = head;
        head = head->next;
        delete p;
    }
}

class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
            ListNode **p = &head;

            while(*p && (*p)->next) {
                ListNode *tmp = *p;
                *p = tmp->next;
                tmp->next = (*p)->next;
                (*p)->next = tmp;
                p = &(tmp->next);
            }
            return head;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    ListNode *head = mkList("1,2,3,4");
    head = s.swapPairs(head);
    cout << "2 1 4 3 == ";
    print(head);
    destroy(head);

    return 0;
}
