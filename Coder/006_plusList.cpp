#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Plus {
public:
	ListNode* plusAB(ListNode* a, ListNode* b) {
		// write code here
		a = _reverse(a);
		b = _reverse(b);
		ListNode* res = nullptr;
		ListNode* cur = nullptr;
		int flag = 0;
		bool first = true;
		while (a || b || flag) {
			if (first) {
				cur = new ListNode(-1);
				res = cur;
				first = false;
			}
			else {
				cur->next = new ListNode(-1);
				cur = cur->next;
			}
			int aval = a ? a->val : 0;
			int bval = b ? b->val : 0;
			cur->val = (aval + bval + flag) % 10;
			flag = (aval + bval + flag >= 10) ? 1 : 0;

			a = a ? a->next : a;
			b = b ? b->next : b;

		}
		ListNode * t = res;
		while (t) {
			cout << t->val << endl;
			t = t->next;
		}
		return _reverse(res);
	}

	ListNode* _reverse(ListNode* a) {
		if (!a)
			return a;
		ListNode* head = a;
		ListNode* cur = a->next;
		a->next = nullptr;
		while (cur) {
			ListNode* tmp = cur->next;
			cur->next = head;
			head = cur;
			cur = tmp;
		}
		return head;
	}
};

int main() {
	ListNode *p1 = new ListNode(0);
	ListNode *p2 = new ListNode(1);
	ListNode *p3 = new ListNode(2);

	ListNode *p4 = new ListNode(0);
	p1->next = p2;
	p2->next = p3;

	Plus s;
	s.plusAB(p1, p4);

	system("pause");
	return 0;
}