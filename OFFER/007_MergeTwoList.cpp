/* Title:
 * ListNode
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        ListNode *cur1 = pHead1, *cur2 = pHead2;
        ListNode head(-1);//这里是局部变量，在栈上申请
        ListNode *h = &head;
        h->next = cur1;
        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur1 = cur1->next;
                h = h->next;
                continue;
            }
            ListNode *cur2_tmp = cur2->next;
            cur2->next = h->next;
            h->next = cur2;
            cur2 = cur2_tmp;
            h = h->next;
        }
        if (cur2)
            h->next = cur2;
        //delete &head;
        return pHead1->val <= pHead2->val?pHead1:pHead2;
    }
    //recursion
    ListNode* Merge1(ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == nullptr) return pHead2;
        if (pHead2 == nullptr) return pHead1;
        if (pHead1->val <= pHead2->val) {
            pHead1->next = Merge1(pHead1->next, pHead2);
            return pHead1;
        }
        pHead2->next = Merge1(pHead1, pHead2->next);
        return pHead2;
    }
};
int main() {
    ListNode p1(1),p2(1),p3(3),p4(3),p5(5),p6(5),p7(7),p8(8),p9(9);
    p1.next = &p3;
    p3.next = &p5;
    p5.next = &p7;
    p7.next = &p9;

    p2.next = &p4;
    p4.next = &p6;
    p6.next = &p8;

    Solution s;
    ListNode *h = s.Merge1(&p1, &p2);
    while (h) {
        cout << h->val << endl;
        h = h->next;
    }
}
