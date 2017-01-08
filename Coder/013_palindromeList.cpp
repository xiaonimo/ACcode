/* Title:
* 回文链表
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};
class Palindrome {
public:
	bool isPalindrome(ListNode* pHead) {
		// write code here
		if (!pHead || !pHead->next)
			return true;
		stack<int> sta;
		ListNode* slow = pHead;
		ListNode* fast = pHead;
		sta.push(slow->val);
		while (fast->next && fast->next->next) {
			slow = slow->next;
			sta.push(slow->val);
			fast = fast->next->next;
		}
		if (fast->next == nullptr)
			sta.pop();
		slow = slow->next;
		while (slow) {
			if (slow->val != sta.top())
				return false;
			sta.pop();
			slow = slow->next;
		}
		return sta.empty();
	}
};

int main(int argc, char *argv[]) {
	
	system("pause");
	return 0;
}

