/*
* # 234
* Palindrome Linked List
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* prev = NULL, *p = head, *post = head->next;
        while (p != NULL) {
            p->next = prev;
            prev = p;
            p = post;
            post = (post != NULL) ? post->next : NULL;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode* p = head, *p_fast = head;
        while (p_fast != NULL && p_fast->next != NULL) {
            p = p->next;
            p_fast = p_fast->next->next;
        }
        ListNode* tail;
        if (p_fast != NULL) {
        // the nodes number of list is odd
            tail = reverseList(p->next);

        } else {
        // the nodes number of list is even
            tail = reverseList(p);
        }

        ListNode* left = head, *right = tail;
        while (right != NULL) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;

    }
};

int main() {
    Solution *s = new Solution();
    ListNode a(1), b(3), c(1), d(3), e(1);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    cout << s->isPalindrome(&a) << endl;
    delete s;
    return 0;
}
