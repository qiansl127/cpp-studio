/*
* # 203
* Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return NULL;
        while (val == head->val) {
            head = head->next;
            if (!head) return NULL;
        }
        ListNode* parent = head;
        ListNode* goal = head->next;
        while (goal) {
            if (val == goal->val) {
                parent->next = goal->next;
            } else {
                parent = goal;
            }
            goal = goal->next;
        }
        return head;
    }
};

int main() {
    ListNode head(1);
    ListNode elem(2);
    ListNode elem2(3);
    head.next = &elem;
    elem.next = &elem2;
    Solution *s = new Solution();
    ListNode* res = s->removeElements(&head, 2);
    cout << res->val << " " << res->next->val << endl;
    delete s;
    return 0;
}
