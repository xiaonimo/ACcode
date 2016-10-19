/* Title:
 * ListNode
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	ListNode *p1 = pListHead, *p2 = pListHead;
    	int ktmp = k;
    	while (ktmp>0 && p1) {
            p1 = p1->next;
            --ktmp;
    	}
    	if (ktmp > 0)
            return nullptr;
        while (p1) {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p2;
    }
    //recursion to reverse listnode
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == nullptr) return pHead;
        if (pHead->next == nullptr)
            return pHead;
        ListNode *head = ReverseList(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return head;
    }
    //loop to reverse listnode
    ListNode* ReverseList1(ListNode *pHead) {
        if (pHead == nullptr) return pHead;
        if (pHead->next == nullptr)
            return pHead;
        ListNode *p1 = pHead;
        ListNode *p2 = pHead->next;
        pHead->next = nullptr;
        while (p2) {
            ListNode *tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }
        return p1;
    }
};
int main() {
    Solution s;
    ListNode p1(-1),p2(2),p3(3),p4(4);
    p1.next = &p2;
    p2.next = &p3;
    p3.next = &p4;
    ListNode *t = s.ReverseList(&p1);
    while (t) {
        cout << t->val <<endl;
        t = t->next;
    }
}
