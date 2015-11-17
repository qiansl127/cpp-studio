/*
* # 25
* Reverse Nodes in k-Group
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
    int getSize(ListNode* head) {
        int size(0);
        while (head != NULL) {
            size++;
            head = head->next;
        }
        return size;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        int size = getSize(head);
        if (k <= 1 || k > size) return head;
        int loops = size/k;
        ListNode *t1 = head, *t2 = t1->next, *t3 = NULL;
        ListNode *lastEnd = NULL, *thisBegin = head, *res = NULL;
        for (int i = 0; i < loops; i++) {
            thisBegin = t1;
            for (int j = 0; j < k-1; j++) {
                t3 = t2->next;
                t2->next = t1;
                t1 = t2;
                t2 = t3;
            }
            if (lastEnd != NULL) lastEnd->next = t1;
            lastEnd = thisBegin;
            if (i == 0) res = t1;
            if (i == loops - 1) thisBegin->next = t2;
            if (t2 != NULL) t3 = t2->next;
            t1 = t2;
            t2 = t3;
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution();
    for (int k = 1; k <= 9; k++) { 
        ListNode* head = new ListNode(1);
        ListNode* t = head;
        int i = 2; 
        while (i <= 9) {
            t->next = new ListNode(i);
            t = t->next;
            i++;
        }
        t = s->reverseKGroup(head, k);
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
