/* Compare two version numbers version1 and version2.
* If version1 > version2 return 1, if version1 < version2 return -1,
* otherwise return 0.

* You may assume that the version strings are non-empty and contain
* only digits and the . character.
* The . character does not represent a decimal point and is used to
* separate number sequences.
* For instance, 2.5 is not "two and a half" or "half way to version three",
* it is the fifth second-level revision of the second first-level revision.

* Here is an example of version numbers ordering:
* 0.1 < 1.1 < 1.2 < 13.37
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
	int compareVersion(string version1, string version2) {
		int cur1 = 0, cur2 = 0;
		//重新构造原来的字符串，方便之后的运算。
		//绝对不能把字符串转换为数值，因为可能发生overflow
		//本方法中认为：1.2>1.12
		version1 = '.' + version1 + '.';
		version2 = '.' + version2 + '.';
		while (cur1 < version1.size() && cur2 < version2.size()) {
			++cur1;
			++cur2;
			while ('0' == version1[cur1])
				++cur1;
			while ('0' == version2[cur2])
				++cur2;
			while ('.' != version1[cur1] && '.' != version2[cur2]) {
				if (version1[cur1] > version2[cur2])
					return 1;
				if (version1[cur1] < version2[cur2])
					return -1;
				++cur1;
				++cur2;
			}
			if ('.' != version1[cur1]) {
				return 1;
			}
			if ('.' != version2[cur2]) {
				return -1;
			}
		}
		return 0;
	}
};

int main()
{
	Solution s = Solution();
	string a1("1");
	cout << (a1 > "2");
	system("pause");
	return 0;
}