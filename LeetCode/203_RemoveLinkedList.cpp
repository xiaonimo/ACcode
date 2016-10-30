/* Remove all elements from a linked list of integers that have value val.
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
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
	//use a pre_node
	ListNode* removeElements(ListNode* head, int val) {
		ListNode *pre = new ListNode(-1);
		ListNode *cur = pre;
		pre->next = head;
		
		while (cur->next) {
			if (cur->next->val != val) {
				cur = cur->next;
				continue;
			}
			ListNode *tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;//Shoule l delete?
		}
		ListNode *res = pre->next;
		delete pre;
		return res;
		//if no pre_node.
		/*if (head->val == val)
			head = head->next;
		return head;*/
	}
	//recursion
	ListNode* removeElements1(ListNode* head, int val) {
		if (!head)
			return head;
		if (head->val == val) {
			ListNode *thead = head->next;
			delete head;
			return removeElements1(thead, val);
		}
		else {
			head->next = removeElements1(head->next, val);
		}
		return head;
	}
	//two star program
	ListNode* removeElements2(ListNode* head, int val) {
		ListNode **cur = &head;
		while (*cur) {
			ListNode *next = (*cur)->next;
			if ((*cur)->val == val) {
				*cur = (*cur)->next;
			}
			else {
				cur = &((*cur)->next);
			}
		}
		return head;
	}

};
int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}