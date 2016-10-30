/* Given an integer, write a function to determine if it is a power of three.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//
	bool isPowerOfThree(int n) {
		if (n <= 0) {
			return false;
		}
		while (n>1) {
			if (n%3 != 0) {
				return false;
			}
			n /= 3;
		}
		return true;
	}
	//no loop or recursion
	bool isPowerOfThree1(int n) {
		if (n <= 0) {
			return false;
		}
		double x = log10(n) / log10(3);
		return floor(x) == x;
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isPowerOfThree1(27) ? "true" : "false") << endl;
	system("pause");
	return 0;
}