/**Title:
 * use two stacks to implement queue.pop and queue.push
 */
#include<iostream>  
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
#include<stack>

using namespace std;
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		int res = 0;
		trans(stack1, stack2);
		res = stack2.top();
		stack2.pop();
		trans(stack2, stack1);
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
	void trans(stack<int> s1, stack<int> &s2) {
		s_clear(s2);
		while (!s1.empty()) {
			auto p = s1.top();
			s2.push(p);
			s1.pop();
		}
	}
	void s_clear(stack<int> &s) {
		while (!s.empty()) s.pop();
	}
};
int main(void)
{
	cout << 0xffffffff;
	system("pause");
	return 0;
}
