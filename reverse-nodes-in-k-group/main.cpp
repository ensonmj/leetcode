#include <iostream>
#include "../lib/include/list.h"

using namespace std;

class Solution {
    public:
        ListNode *reverseKGroup(ListNode *head, int k) {
            ListNode **tail = &head;
            for(int i=0; i<k; ++i) {
                if(*tail) {
                    tail = &(*tail)->next;
                } else {
                    return head;
                }
            }

            ListNode *p = reverseKGroup(*tail, k);
            *tail = p; //update new tail
            return reverseList(head, p);
        }
    private:
        ListNode *reverseList(ListNode *head, ListNode *tail) {
            if(!head || head == tail || head->next == tail) {
                return head;
            }

            ListNode *p = reverseList(head->next, tail);
            head->next->next = head;
            head->next = tail;

            return p;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;
    ListNode *head = mkList("1,2,3,4,5");
    int k = 2;
    head = s.reverseKGroup(head, k);
    cout << "2 1 4 3 5 == ";
    printList(head);
    destroyList(head);

    head = mkList("1,2,3,4,5");
    k = 3;
    head = s.reverseKGroup(head, k);
    cout << "3 2 1 4 5 == ";
    printList(head);
    destroyList(head);

    return 0;
}
