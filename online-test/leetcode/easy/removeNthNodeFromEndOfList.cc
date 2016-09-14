/*
* # 19
* Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return NULL;
        ListNode* t1 = head;
        int size = 1;
        for (; t1->next != NULL; t1 = t1->next) {
            size++;
        }
        if (size - n == 0) return head->next;
        t1 = head;
        for (int i = size - n; i > 1; i--) {
            t1 = t1->next;
        }
        t1->next = t1->next->next;
        return head;
    }
};

int main() {
    Solution *s = new Solution();
    ListNode a(1), b(2), c(3), d(4), e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode* h = s->removeNthFromEnd(&a, 2);
    for (; h != NULL; h = h->next) {
        cout << h->val << " ";
    }
    cout << endl;
    delete s;
    return 0;
}
