/* Design a stack that supports push, pop, top, and 
 * retrieving the minimum element in constant time.
 * push(x) -- Push element x onto stack.
 * pop() ---- Removes the element on top of the stack.
 * top() ---- Get the top element.
 * getMin() - Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
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

//56ms,use two stacks
class MinStack {
	stack<int> store, help;
public:
	/** initialize your data structure here. */
	MinStack() {
		
	}

	void push(int x) {
		store.push(x);
		if (help.empty()) {
			help.push(x);
		}
		else {
			help.push(min(help.top(), x));
		}
	}

	void pop() {
		store.pop();
		help.pop();
	}

	int top() {
		return store.top();
	}

	int getMin() {
		return help.top();
	}
};
//use two stacks.
class MinStack1 {
	stack<int> store, help;
public:
	/** initialize your data structure here. */
	MinStack1() {

	}

	void push(int x) {
		store.push(x);
		if (help.empty() || x <= help.top()) {
			help.push(x);
		}
	}

	void pop() {
		if (store.top() == help.top())
			help.pop();
		store.pop();
	}

	int top() {
		return store.top();
	}

	int getMin() {
		return help.top();
	}
};
int main()
{
	MinStack1 a = MinStack1();
	a.push(0);
	a.push(1);
	a.push(0);
	cout << a.top() << a.getMin() << endl;
	a.pop();
	cout << a.top() << a.getMin() << endl;
	system("pause");
	return 0;
}