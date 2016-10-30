/* Write a function to delete a node (except the tail) in a singly linked list, 
 * given only access to that node.

 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node 
 * with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
	void deleteNode(ListNode* node) {
		if (!node || !node->next) {
			return;
		}
		ListNode *tmp = node->next;
		node->next = node->next->next;
		node->val = tmp->val;
		//Stack overflow says that delete will free the memory 
		//and call the deconstructor,while free only free the memory.
		delete tmp;
		return;
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

	s.deleteNode(p4);
	while (p1) {
		cout << p1->val;
		p1 = p1->next;
	}
	system("pause");
	return 0;
}