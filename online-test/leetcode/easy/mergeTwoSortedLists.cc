/*
* # 21
* Merge Two Sorted Lists
*/

#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        int v(l1->val), v2(l2->val);
        ListNode* t = new ListNode(0);
        ListNode* preHead = t;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                t->next = l1;
                l1 = l1->next;
            } else {
                t->next = l2;
                l2 = l2->next;
            }
            t = t->next;
        }
        if (l1 == NULL) {
            t->next = l2;
        } else if (l2 == NULL) {
            t->next = l1;
        }
        ListNode* head = preHead->next;
        delete preHead;
        return head;
    }
};

int main() {
    Solution *s = new Solution();
    ListNode a1(-1), a2(3), a3(9);
    ListNode b1(2), b2(4), b3(7);
    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    ListNode* res = s->mergeTwoLists(&a1, &b1);
    while (res != NULL) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    delete s;
    return 0;
}
