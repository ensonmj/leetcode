#include <iostream>
#include <vector>
#include <climits>

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

// two slow
//class Solution {
//    public:
//        ListNode *mergeKLists(vector<ListNode *> &lists) {
//            if(lists.empty()) {
//                return nullptr;
//            }

//            if(lists.size() == 1) {
//                return lists[0];
//            }

//            ListNode *head=nullptr, *tail=nullptr, **pre=nullptr;
//            while(!lists.empty()) {
//                int val = INT_MAX;
//                for(auto iter = lists.begin(); iter != lists.end();) {
//                    if(*iter == nullptr) {
//                        iter = lists.erase(iter);
//                    } else {
//                        if((*iter)->val <= val) {
//                            val = (*iter)->val;
//                            pre = &*iter;
//                        }
//                        ++iter;
//                    }
//                }

//                if(!pre) {
//                    break; // no more node
//                } else {
//                    if(!head) {
//                        head = tail = *pre;
//                    } else {
//                        tail->next = *pre;
//                        tail = *pre;
//                    }
//                    *pre = (*pre)->next; //move head to next
//                    pre = nullptr;
//                }
//            }

//            return head;
//        }
//};

//class Solution {
//    public:
//        ListNode *mergeKLists(vector<ListNode *> &lists) {
//            if(lists.empty()) {
//                return nullptr;
//            }

//            if(lists.size() == 1) {
//                return lists.front();
//            }

//            ListNode *head = nullptr, *p = nullptr;
//            for(auto iter = lists.begin(); iter != lists.end(); ++iter) {
//                if(!*iter) {
//                    continue;
//                }
//                if(!head) {
//                    head = p = *iter;
//                } else {
//                    while(p->next) {
//                        p = p->next;
//                    }
//                    p->next = *iter;
//                }
//           }

//            return sortList(head);
//        }

//    private:
//        ListNode *sortList(ListNode *head) {
//            if(!head || !head->next) {
//                return head;
//            }

//            ListNode *p = getMid(head);
//            ListNode *next = p->next;
//            p->next = nullptr;

//            return mergeList(sortList(head), sortList(next));
//        }

//        ListNode *getMid(ListNode *head) {
//            ListNode *slow = head, *fast=head->next;
//            while(fast && fast->next) {
//                slow = slow->next;
//                fast = fast->next->next;
//            }

//            return slow;
//        }

//        ListNode *mergeList(ListNode *first, ListNode *second) {
//            if(!second) {
//                return first;
//            }

//            ListNode *head, *p1, *p2;
//            if(first->val <= second->val) {
//                head = p1 =  first;
//                p2 = second;
//            } else {
//                head = p1 = second;
//                p2 = first;
//            }

//            while(p1->next && p2) {
//                if(p1->next->val <= p2->val) {
//                    p1 = p1->next;
//                } else {
//                    ListNode *tmp = p1->next;
//                    p1->next = p2;
//                    p1 = p2;
//                    p2 = tmp;
//                }
//            }
//            p1->next = p2;

//            return head;
//        }
//};

//merge directly, more fast
class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            if(lists.empty()) {
                return nullptr;
            }

            if(lists.size() == 1) {
                return lists.front();
            }

            return mergeKLists(lists.begin(), lists.end());
        }

    private:
        ListNode *mergeKLists(vector<ListNode *>::const_iterator begin,
                vector<ListNode *>::const_iterator end) {
            int len = end - begin;
            if(len<=1) {
                return *begin;
            }
            return mergeLists(mergeKLists(begin, begin+len/2),
                    mergeKLists(begin+len/2, end));
        }

        ListNode *mergeLists(ListNode *first, ListNode *second) {
            if(!first) {
                return second;
            }
            if(!second) {
                return first;
            }

            ListNode *head, *p1, *p2;
            if(first->val <= second->val) {
                head = p1 =  first;
                p2 = second;
            } else {
                head = p1 = second;
                p2 = first;
            }

            while(p1->next && p2) {
                if(p1->next->val <= p2->val) {
                    p1 = p1->next;
                } else {
                    ListNode *tmp = p1->next;
                    p1->next = p2;
                    p1 = p2;
                    p2 = tmp;
                }
            }
            p1->next = p2;

            return head;
        }
};

int main(int argc, char const* argv[]) {
    Solution s;

    // no elements
    vector<ListNode *> vec;
    ListNode *head = s.mergeKLists(vec);
    print(head);
    destroy(head);

    // one null elements
    head = nullptr;
    vec.push_back(head);
    head = s.mergeKLists(vec);
    print(head);
    destroy(head);

    // two null elements
    head = nullptr;
    vec.push_back(head);
    vec.push_back(head);
    head = s.mergeKLists(vec);
    print(head);
    destroy(head);

    head = mkList("1, 2, 3");
    vec.push_back(head);
    head = mkList("4, 5");
    vec.push_back(head);
    head = s.mergeKLists(vec);
    print(head);
    destroy(head);

    return 0;
}
