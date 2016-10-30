/* Implement the following operations of a stack using queues.
 * push(x) -- Push element x onto stack.
 * pop() ---- Removes the element on top of the stack.
 * top() ---- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- 
 * which means only push to back, peek/pop from front, size, 
 * and is empty operations are valid.
 * You may assume that all operations are valid (for example, 
 * no pop or top operations will be called on an empty stack).
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;
//use two queues
class Stack {
	queue<int> p,q;
public:
	// Push element x onto stack.
	void push(int x) {
		queue<int> &pt = p.empty() ? q : p;
		queue<int> &qt = q.empty() ? q : p;
		qt.push(x);
		auto sz = pt.size();
		for (decltype(sz) i = 0; i < sz; ++i) {
			int tmp = pt.front();
			qt.push(tmp);
			pt.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		(p.empty() ? q : p).pop();
	}

	// Get the top element.
	int top() {
		return p.empty()?q.front():p.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return p.empty()&&q.empty();
	}
};
//use one queue
class Stack1 {
	queue<int> q;
public:
	// Push element x onto stack.
	void push(int x) {
		q.push(x);
		auto sz = q.size();
		for (decltype(sz) i = 1; i < sz; ++i) {
			q.push(q.front());
			q.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		q.pop();
	}

	// Get the top element.
	int top() {
		return q.front();
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
};
int main()
{
	Stack1 a = Stack1();
	a.push(1);
	a.push(2);
	a.push(3);
	cout << a.top() << endl;
	a.pop();
	cout << a.top() << endl;
	cout << a.empty();
	system("pause");
	return 0;
}