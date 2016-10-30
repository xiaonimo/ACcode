/* Reverse a singly linked list.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
}stu;

class Solution {
public:
	//12ms
	ListNode* reverseList(ListNode* head) {
		if (!head) {
			return head;
		}
		ListNode *ptail;
		ListNode *phead = head;
		while (phead->next) {
			phead = phead->next;
		}
		ptail = phead;
		while (head != ptail) {
			ListNode *tmp = head->next;
			head->next = ptail->next;
			ptail->next = head;
			head = tmp;
		}
		return ptail;
	}
	//8ms.in place
	ListNode* reverseList1(ListNode* head) {
		if (!head) {
			return head;
		}
		ListNode *tmp1, *tmp2;
		tmp1 = head->next;
		head->next = nullptr;
		while (tmp1) {
			tmp2 = tmp1->next;
			tmp1->next = head;
			head = tmp1;
			tmp1 = tmp2;
		}
		return head;
	}
};
int main()
{
	Solution s = Solution();
	stu *n1 = new ListNode(1);
	stu *n2 = new ListNode(2);
	stu *n3 = new ListNode(3);
	stu *n4 = new ListNode(4);
	stu *n5 = new ListNode(5);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	ListNode *l = s.reverseList1(n1);
	while (l) {
		cout << l->val << endl;
		l = l->next;
	}

	system("pause");
	return 0;
}