/*
* # 24
* Swap Nodes In Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *t1 = head, *t2 = t1->next, *res = t2, *t3 = NULL, *t4 = NULL;
        while (t1 != NULL) {
            t2 = t1->next;
            t3 = (t2 != NULL)? t2->next : NULL;
            t4 = (t3 != NULL)? t3->next : NULL;
            if (t4 != NULL) {
                t2->next = t1;
                t1->next = t4;
                t1 = t3;
            } else if (t3 != NULL) {
                t2->next = t1;
                t1->next = t3;
                t3->next = NULL;
                break;
            } else if (t2 != NULL) {
                t2->next = t1;
                t1->next = NULL;
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    for (int size = 2; size <= 9; size++) { 
        ListNode* head = new ListNode(1);
        ListNode* t = head;
        int i = 2; 
        while (i < size) {
            t->next = new ListNode(i);
            t = t->next;
            i++;
        }
        t = s->swapPairs(head);
        while (t != NULL) {
            cout << t->val << " ";
            ListNode* pre = t;
            t = t->next;
            delete pre;
        }
        cout << endl;
    }
    delete s;
    return 0;
}
