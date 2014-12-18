#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x, ListNode *p=nullptr) : val(x), next(p) {}
};

class Solution
{
    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if(!l1) {
                return l2;
            }
            if(!l2) {
                return l1;
            }
            ListNode *head = l1;
            int carry = 0;
            int sum = 0;

            while(l1->next && l2->next) {
                sum = l1->val + l2->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
                l1 = l1->next;
                l2 = l2->next;
            }

            if(!l1->next) {
                sum = l1->val + l2->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;

                l1->next = l2->next;
                while(l1->next) {
                    l1 = l1->next;
                    sum = l1->val + carry;
                    l1->val = sum % 10;
                    carry = sum / 10;
                }

                if(carry) {
                    l1->next = new ListNode(carry);
                }
            } else if(!l2->next) {
                sum = l1->val + l2->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
                while(l1->next) {
                    l1 = l1->next;
                    sum = l1->val + carry;
                    l1->val = sum % 10;
                    carry = sum / 10;
                }

                if(carry) {
                    l1->next = new ListNode(carry);
                }
            }

            return head;
        }
};

int main(int argc, char** argv)
{
    ListNode *l1, *l2, *head;
    Solution s;

    //7->0->8
    l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    head = s.addTwoNumbers(l1, l2);
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;

    //0->0->1
    l1 = new ListNode(1);
    l2 = new ListNode(9, new ListNode(9));
    head = s.addTwoNumbers(l1, l2);
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;

    //0->1
    l1 = new ListNode(5);
    l2 = new ListNode(5);
    head = s.addTwoNumbers(l1, l2);
    while(head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "null" << endl;

    return 0;
}
