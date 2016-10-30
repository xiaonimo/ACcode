/* Given a linked list, remove the nth node from the end of list and return its head.
 * For example,
 * Given linked list: 1->2->3->4->5, and n = 2.
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	//counter
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *thead = head;
		int nodes = 0;
		while (head) {
			++nodes;
			head = head->next;
		}
		nodes -= n;
		if (!nodes) {
			ListNode *tmp = thead->next;
			delete thead;
			return tmp;
		}
		head = thead;
		while (nodes--) {
			head = head->next;
		}
		ListNode *tmp = head->next;
		head->next = tmp->next;
		delete tmp;
		return thead;
	}
	ListNode* removeNthFromEnd1(ListNode* head, int n) {
		if (!head)
			return head;
		ListNode *pre_head = new ListNode(-1);
		pre_head->next = head;
		ListNode *cur1 = pre_head, *cur2 = pre_head;

		while (n--)
			cur1 = cur1->next;
		while (cur1->next) {
			cur2 = cur2->next;
			cur1 = cur1->next;
		}
		ListNode *tmp1 = cur2->next;
		cur2->next = tmp1->next;
		delete tmp1;
		ListNode *tmp2 = pre_head->next;
		delete pre_head;
		return tmp2;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}