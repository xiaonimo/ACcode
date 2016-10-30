/* Given a linked list, swap every two adjacent nodes and return its head.

 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.

 * Your algorithm should use only constant space. 
 * You may not modify the values in the list, only nodes itself can be changed.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>
using namespace std;

typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
}node;
class Solution {
public:
	//4ms
	ListNode* swapPairs(ListNode* head) {
		ListNode *res1 = new ListNode(0);
		ListNode *res2 = res1;
		res1->next = head;
		while (res1->next && res1->next->next) {
			ListNode *tmp = res1->next;
			res1->next = res1->next->next;
			res1 = res1->next;
			tmp->next = res1->next;
			res1->next = tmp;
			res1 = res1->next;
		}
		ListNode *res3 = res2->next;
		delete res2;
		return res3;
	}
};

int main()
{
	Solution s = Solution();
	node *p1 = new ListNode(1);
	node *p2 = new ListNode(2);
	node *p3 = new ListNode(3);
	node *p4 = new ListNode(4);
	node *p5 = new ListNode(5);
	node *p6 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;

	node *head = s.swapPairs(p1);
	while (head) {
		cout << head->val;
		head = head->next;
	}
	system("pause");
	return 0;
}