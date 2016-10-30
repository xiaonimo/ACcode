/* Given an integer, write a function to determine if it is a power of two.
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
	//8ms
	bool isPowerOfTwo(int n) {
		if (n <= 0) {
			return false;
		}
		int res;
		while (n>1) {
			res = n >> 1;
			if ((res << 1) != n) {
				return false;
			}
			n = res;
		}
		return true;
	}
	//O(1).brilliant function
	bool isPowerOfTwo1(int n) {
		return (n > 0) && !(n&(n - 1));
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isPowerOfTwo1(16) ? "true" : "false") << endl;
	system("pause");
	return 0;
}