/* Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together 
 * the nodes of the first two lists.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
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
	//12ms,by default,it's asc
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!(l1 && l2)) {
			return l1 ? l1 : l2;
		}
		struct ListNode *res = new ListNode(0);
		ListNode *head = res;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				res->next = l1;
				l1 = l1->next;
			}
			else {
				res->next = l2;
				l2 = l2->next;
			}
			res = res->next;
		}
		if (!l1) {
			res->next = l2;
		}
		else {
			res->next = l1;
		}
		return head->next;
	}
	//12ms,you shoule delete the newed node.
	ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
		struct ListNode *res = new ListNode(0);
		ListNode *res_tmp = res;
		while (l1 && l2) {
			ListNode *&p = l1->val < l2->val ? l1 : l2;
			res->next = p;
			res = res->next;
			p = p->next;
		}

		res->next = l1 ? l1 : l2;

		ListNode *head = res_tmp->next;
		delete res_tmp;
		return head;
	}
};
int main()
{
	Solution s = Solution();
	stu *a1 = new ListNode(0);
	stu *a2 = new ListNode(2);
	stu *a3 = new ListNode(3);
	stu *a4 = new ListNode(10);
	stu *a5 = new ListNode(11);
	stu *b1 = new ListNode(1);
	stu *b2 = new ListNode(5);
	stu *b3 = new ListNode(6);
	stu *b4 = new ListNode(8);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;

	ListNode *res = s.mergeTwoLists1(a1, b1);
	while (res) {
		cout << res->val << endl;
		res = res->next;
	}
	system("pause");
	return 0;
}