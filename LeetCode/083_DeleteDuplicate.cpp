/* Given a sorted linked list, delete all duplicates such that each element 
 * appear only once.

 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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
	//16ms.It's too complex.We can solve the problem using one ptr.
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head) {
			return head;
		}
		ListNode *cur = head;
		ListNode *prv = head->next;
		while (prv) {
			if (prv->val != cur->val && cur->next == prv) {
				cur = cur->next;
			}
			if (prv->val != cur->val && cur->next != prv){
				cur->next = prv;
				cur = cur->next;
			}
			prv = prv->next;
		}
		cur->next = nullptr;
		return head;
	}
	//16ms
	ListNode* deleteDuplicates1(ListNode* head) {
		ListNode *cur = head;
		while (cur && cur->next) {
			if (cur->val == cur->next->val) {
				ListNode *tmp = cur->next->next;
				delete cur->next;//l think the duplicate nodes should be free 
				cur->next = tmp;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}
};
int main()
{
	Solution s = Solution();
	stu *n1 = new ListNode(1);
	stu *n2 = new ListNode(2);
	stu *n3 = new ListNode(2);
	stu *n4 = new ListNode(4);
	stu *n5 = new ListNode(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	ListNode *l = s.deleteDuplicates1(n1);
	while (l) {
		cout << l->val << endl;
		l = l->next;
	}

	system("pause");
	return 0;
}