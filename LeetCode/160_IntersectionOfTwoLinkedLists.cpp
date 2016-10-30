/* Write a program to find the node at which the 
 * intersection of two singly linked lists begins.
 * For example, the following two linked lists:
		A:          a1 → a2
						   ↘
							 c1 → c2 → c3
						   ↗            
		B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 * - If the two linked lists have no intersection at all, return null.
 * - The linked lists must retain their original structure after the function returns.
 * - You may assume there are no cycles anywhere in the entire linked structure.
 * - Your code should preferably run in O(n) time and use only O(1) memory.
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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int alen = 0, blen = 0;
		ListNode *theadA = headA, *theadB = headB;
		while (theadA) {
			++alen;
			theadA = theadA->next;
		}
		while (theadB) {
			++blen;
			theadB = theadB->next;
		}
		ListNode *&tmp = alen > blen ? headA : headB;
		for (int i = 0; i < abs(alen - blen); ++i) {
			tmp = tmp->next;
		}
		while (headA) {
			if (headA == headB)
				return headA;
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}
	//Another awesome solution
	ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
		if (!headA || !headB)
			return NULL;
		ListNode *theadA = headA, *theadB = headB;
		while (theadA != theadB) {
			theadA = theadA->next;
			theadB = theadB->next;
			if (theadA == theadB)
				return theadA;
			if (!theadA)
				theadA = headB;
			if (!theadB)
				theadB = theadA;
		}
		return theadA;
	}
};
int main()
{
	Solution s = Solution();

	
	system("pause");
	return 0;
}