/* Title:
 * 字符串翻转
 */

#include <iostream>
#include <string>
using namespace std;

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (!pHead)
			return pHead;

		ListNode* pInsert = pHead;
		ListNode* newHead = new ListNode(-1);
		newHead->next = pHead;

		if (pHead->val >= x)
			pInsert = newHead;
		else {
			while (pHead->next && pHead->next->val < x)
				pHead = pHead->next;
			pInsert = pHead;
		}

		ListNode* ppre = pHead;
		pHead = pHead->next;
		while (pHead) {
			if (pHead->val >= x) {
				ppre = pHead;
				pHead = pHead->next;
				continue;
			}
			ppre->next = pHead->next;
			pHead->next = pInsert->next;
			pInsert->next = pHead;
			pInsert = pInsert->next;
			pHead = ppre->next;
		}

		ListNode* res = newHead->next;
		delete newHead;
		return res;
	}
};
 int main(int argc, char *argv[]) {
    
}

