/*
* # 160
* Intersection of Two Linked Lists
*/

#include<iostream>
#include<vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int getLength(ListNode* h) {
        int length(1);
        ListNode* p = h;
        while (p->next != NULL) {
            length++;
            p = p->next;
        }
        return length;
    }
    ListNode *shiftNode(ListNode* p, int l) {
        while (p != NULL && l > 0) {
            p = p->next;
            l--;
        }
        return p;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lengthA = getLength(headA), lengthB = getLength(headB);
        ListNode* a = headA;
        ListNode* b = headB;
        int delta = lengthA - lengthB;
        if (delta > 0) {
            a = shiftNode(a, delta);
        } else {
            b = shiftNode(b, -delta);
        }
        while (a != NULL && b != NULL) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }
        return NULL; 
    }
};

int main() {
    Solution *s = new Solution();
    ListNode a1(11), a2(12);
    ListNode b1(21), b2(22), b3(23);
    ListNode c1(31), c2(32), c3(33);
    c1.next = &c2;
    c2.next = &c3;
    a1.next = &a2;
    a2.next = &c1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    ListNode* res = s->getIntersectionNode(&a1, &b1);
    if (res)
        cout << res->val << endl;
    delete s;
    return 0;
}
