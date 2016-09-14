/*
* # 2
* Add Two Numbers
*/

/*
* (1 -> 4 -> 3) + (5 -> 6 -> 4)
* return 6 -> 0 -> 8
*/

#include<iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode root = ListNode(0);
        ListNode* pointer = &root;
        int lhs = 0, rhs = 0, sum = 0, append = 0;
        while (l1 || l2) {
            lhs = (l1 ? l1->val : 0);
            rhs = (l2 ? l2->val : 0);
            sum = lhs + rhs + append;
            append = sum / 10;
            pointer->next = new ListNode(sum % 10);
            pointer = pointer->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (append) {
            pointer->next = new ListNode(1);
        }
        return root.next;
    }
    ListNode* generate(int a, int b, int c) {
        ListNode* l = new ListNode(a);
        l->next = new ListNode(b);
        l->next->next = new ListNode(c);
        return l;
    }
    void print(ListNode* l) {
        cout << l->val << " -> " << l->next->val << " -> " << l->next->next->val << endl;
    }
    void clean(ListNode* l) {
        delete l->next->next;
        delete l->next;
        delete l;
    }
};

int main() {
    Solution *s = new Solution();
    ListNode* l1 = s->generate(1, 4, 3);
    ListNode* l2 = s->generate(5, 6, 4);
    s->print(l1);
    s->print(l2);

    ListNode* res = s->addTwoNumbers(l1, l2);
    s->print(res);

    s->clean(l1);
    s->clean(l2);
    s->clean(res);

    delete s;
    return 0;
}
