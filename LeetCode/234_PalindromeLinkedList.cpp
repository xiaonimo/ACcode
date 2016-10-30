/* Given a singly linked list, determine if it is a palindrome.

 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
#include <sstream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//beats 100%
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		auto cur1 = head, cur2 = head;
		while (cur2->next && cur2->next->next) {
			cur1 = cur1->next;
			cur2 = cur2->next->next;
		}
		ListNode *pre = cur1;
		ListNode *cur = cur1->next;
		cur1->next = nullptr;//The key point.
		while (cur) {
			auto next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		while (pre && head) {
			if (pre->val != head->val)
				return false;
			pre = pre->next;
			head = head->next;
		}
		return true;
	}

	bool isPalindrome1(ListNode* head) {
		if (!head || !head->next)
			return true;
		auto cur1 = head, cur2 = head;
		while (cur2->next && cur2->next->next) {
			cur1 = cur1->next;
			cur2 = cur2->next->next;
		}
		cur1 = reverse(cur1->next);
		while (head && cur1) {
			if (cur1->val != head->val)
				return false;
			cur1 = cur1->next;
			head = head->next;
		}
		return true;
	}
	ListNode* reverse(ListNode *head) {
		if (!head || !head->next)
			return head;
		ListNode *cur = head;
		ListNode *pre = nullptr;//The key point
		while (cur) {
			ListNode *next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}
};
int main()
{
	Solution s = Solution();
	
	ListNode p1(1);
	ListNode p2(2);
	ListNode p3(2);
	ListNode p4(1);
	ListNode p5(1);
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p4;
	//p4.next = &p5;
	cout << (s.isPalindrome(&p1)?"true":"false");
	system("pause");
	return 0;
}