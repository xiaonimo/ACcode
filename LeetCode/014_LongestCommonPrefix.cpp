/* Write a function to find the longest 
 * common prefix string amongst an array of strings.
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
typedef unsigned int uint32_t;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return string();
		if (strs.size() == 1)
			return strs[0];
		sort(begin(strs), end(strs));
		auto sz = min(strs[0].size(), strs[strs.size() - 1].size());
		decltype(sz) i = 0;
		while (i < sz && strs[0][i] == strs[strs.size() - 1][i]) {
			++i;
		}
		return string(begin(strs[0]), begin(strs[0]) + i);
	}
};
int main()
{
	
	system("pause");
	return 0;
}