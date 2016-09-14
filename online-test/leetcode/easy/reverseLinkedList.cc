/*
* # 206
* Reverse Linked List
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;
        ListNode *i = head, *j = head->next, *k;
        while (j) {
            k = j->next;
            j->next = i;
            i = j;
            j = k;
        }
        head->next = NULL;
        return i;
    }
};

int main() {
    ListNode head(1);
    ListNode elem(2);
    head.next = &elem;
    Solution *s = new Solution();
    ListNode* res = s->reverseList(&head);
    cout << res->val << " " << res->next->val << endl;
    delete s;
    return 0;
}
