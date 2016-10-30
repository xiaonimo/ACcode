/* Given a linked list, determine if it has a cycle in it.

 * Follow up:
 * Can you solve it without using extra space?
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
	//12ms,fast ptr will catch the slow ptr if there is a cycle;
	bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast && fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
				return true;
		}
		return false;
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
	//a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = b1;
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = a3;

	cout << (s.hasCycle(a1) ? "true" : "false");
	system("pause");
	return 0;
}