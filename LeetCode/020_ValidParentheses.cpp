/* Given a string containing just the characters '(', ')', 
 * '{', '}', '[' and ']', determine if the input string is valid.

 * The brackets must close in the correct order, "()" and "()[]{}" 
 * are all valid but "(]" and "([)]" are not.
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

class Solution {
public:
	//3ms,slow
	bool isValid(string s) {
		if (s.empty())
			return true;
		unordered_map<char, int> hmap;
		// char hamp[255] = {0};//0ms
		hmap['('] = 10;
		hmap[')'] = 11;
		hmap['['] = 20;
		hmap[']'] = 21;
		hmap['{'] = 30;
		hmap['}'] = 31;
		stack<char> par;
		par.push('a');
		for (int i = 0; i < (int)s.size(); ++i) {
			if (!hmap[s[i]])
				continue;
			else if (hmap[par.top()]+1 == hmap[s[i]])
				par.pop();
			else
				par.push(s[i]);
		}
		return par.size() == 1;
	}
	bool isValid1(string s) {
		stack<char> par;
		par.push('a');
		for (auto &c : s) {
			switch (c) {
			case '(':
			case '[':
			case '{':
				par.push(c);
				break;
			case ')':
				if (par.top() != '(')
					return false;
				par.pop();
				break;
			case ']':
				if (par.top() != '[')
					return false;
				par.pop();
				break;
			case '}':
				if (par.top() != '{')
					return false;
				par.pop();
				break;
			default:
				break;
			}
		}
		return par.size() == 1;
	}
};
int main()
{
	Solution s = Solution();

	
	system("pause");
	return 0;
}