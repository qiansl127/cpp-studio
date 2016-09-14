/*
* # 23
* Merge K Sorted Lists
*/

#include<iostream>
#include<vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        int k = lists.size();
        vector<ListNode*> left(lists.begin(), lists.begin() + k/2);
        vector<ListNode*> right(lists.begin() + k/2, lists.end());
        ListNode* l = mergeKLists(left);
        ListNode* r = mergeKLists(right);
        return mergeTwoLists(l, r);
    }
};

int main() {
    ListNode a1(2), a2(7), a3(11);
    ListNode b1(-1), b2(3), b3(4);
    ListNode c1(0), c2(5), c3(9), c4(12);
    a1.next = &a2;
    a2.next = &a3;
    b1.next = &b2;
    b2.next = &b3;
    c1.next = &c2;
    c2.next = &c3;
    c3.next = &c4;
    vector<ListNode*> lvec;
    lvec.push_back(&a1);
    lvec.push_back(&b1);
    lvec.push_back(&c1);

    Solution *s = new Solution();
    ListNode* pl = s->mergeKLists(lvec);
    for (ListNode* i = pl; i != NULL; i = i->next) cout << i->val << " ";
    cout << endl;
    delete s;
    return 0;
}
