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
        // given n will always be valid
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            ListNode **slow = &head;
            ListNode *fast = head;
            while(n--) {
                fast = fast->next;
            }
            while(fast) {
                fast = fast->next;
                slow = &(*slow)->next;
            }

            ListNode *p = *slow;
            *slow = (*slow)->next;
            delete p;

            return head;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    const char *str = "3,1,5,4";
    int n = 2;
    ListNode *head = mkList(str);
    cout << "3 1 4 == ";
    print(head=s.removeNthFromEnd(head, n));
    destroy(head);

    str = "3,1,5,4";
    n = 1;
    head = mkList(str);
    cout << "3 1 5 == ";
    print(head=s.removeNthFromEnd(head, n));
    destroy(head);

    str = "1";
    n = 1;
    head = mkList(str);
    cout << " == ";
    print(head=s.removeNthFromEnd(head, n));
    destroy(head);

    str = "1,2";
    n = 2;
    head = mkList(str);
    cout << "2 == ";
    print(head=s.removeNthFromEnd(head, n));
    destroy(head);

    return 0;
}
