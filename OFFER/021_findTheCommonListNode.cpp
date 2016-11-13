/* Title:
 * 输入两个链表，找出它们的第一个公共结点。
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1 || !pHead2) return nullptr;

        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        int l1=0,l2=0,len;
        while (cur1) {
            ++l1;
            cur1 = cur1->next;
        }
        while (cur2) {
            ++l2;
            cur2 = cur2->next;
        }
        ListNode* &tmp = l1>l2?pHead1:pHead2;
        len = abs(l1-l2);
        while (len) {
            --len;
            tmp = tmp->next;
        }
        while (pHead1 != pHead2) {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }

    ListNode* FindFirstCommonNode1( ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1 || !pHead2) return nullptr;

        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;

        while (cur1 != cur2) {
            cur1 = (cur1 == nullptr?pHead2:cur1->next);
            cur2 = (cur2 == nullptr?pHead1:cur2->next);
        }
        return cur1;
    }
};

int main(int argc, char *argv[]) {
    ListNode* p1 = new ListNode(1);
    ListNode* p2 = new ListNode(2);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    p1->next = p2;
    p2->next = p3;
    p4->next = p3;

    Solution s;
    cout << (s.FindFirstCommonNode1(p1, p4)->val);
    return 0;
}
