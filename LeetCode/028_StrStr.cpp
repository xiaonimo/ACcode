/* Implement strStr().

 * Returns the index of the first occurrence of needle 
 * in haystack, or -1 if needle is not part of haystack.
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
	// my understand about KMP
	int strStr(string haystack, string needle) {
		if (needle.empty())
			return 0;
		if (haystack.empty() || haystack.size() < needle.size())
			return -1;
		vector<int> next = genNext(needle);
		for (int ihay = 0; ihay <= int(haystack.size() - needle.size());) {
			int inee = 0;
			for (; inee < (int)needle.size(); ++inee) {
				if (needle[inee] != haystack[ihay + inee])
					break;
			}
			if (inee == needle.size())
				return ihay;
			ihay += (inee - next[inee]);
		}
		return -1;
	}
	vector<int> genNext(string needle) {
		vector<int> next(needle.size(), -1);
		if (needle.size() == 1)
			return next;
		next[1] = 0;
		for (int i = 2; i < (int)needle.size(); ++i) {
			int cur = i;
			while (cur>1) {
				if (needle[i - 1] == needle[next[cur - 1]]) {
					next[i] = next[cur - 1] + 1;
					break;
				}
				cur = next[next[cur - 1]];
			}
			if (cur <= 1)
				next[i] = 0;
		}
		return next;
	}
};
int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}