/* Implement the following operations of a queue using stacks.
 * push(x) -- Push element x to the back of queue.
 * pop() ---- Removes the element from in front of queue.
 * peek() --- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only 
 * push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. 
 * You may simulate a stack by using a list or deque (double-ended queue), 
 * as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no 
 * pop or peek operations will be called on an empty queue).
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

//0ms
class Queue {
public:
	stack<int> s_main;
	stack<int> s_help;
	// Push element x to the back of queue.
	void push(int x) {
		s_main.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		if (s_main.empty())
			return;
		while (!s_main.empty()) {
			int tmp = s_main.top();
			s_help.push(tmp);
			s_main.pop();
		}
		s_help.pop();
		while (!s_help.empty()) {
			int tmp = s_help.top();
			s_main.push(tmp);
			s_help.pop();
		}
	}

	// Get the front element.
	int peek(void) {
		while (!s_main.empty()) {
			int tmp = s_main.top();
			s_help.push(tmp);
			s_main.pop();
		}
		int res = s_help.top();
		while (!s_help.empty()) {
			int tmp = s_help.top();
			s_main.push(tmp);
			s_help.pop();
		}
		return res;
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s_main.empty();
	}
};
class Queue1 {
	stack<int> input, output;
public:
	// Push element x to the back of queue.
	void push(int x) {
		input.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		peek();
		output.pop();
	}

	// Get the front element.
	int peek(void) {
		if (output.empty()) {
			while (!input.empty()) {
				output.push(input.top());
				input.pop();
			}
		}
		return output.top();
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return input.empty() && output.empty();
	}
};
int main()
{
	Queue1 q = Queue1();
	cout << (q.empty() ? "true" : "false") << endl;
	q.push(1);
	cout << "push 1 ok" << endl;
	cout << q.peek() <<endl;
	q.push(2);
	q.push(1);
	q.pop();
	cout << q.peek() << endl;
	system("pause");
	return 0;
}