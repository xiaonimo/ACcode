/* Given an integer (signed 32 bits), write a function to check 
 * whether it is a power of 4.

 * Example:
 * Given num = 16, return true. Given num = 5, return false.

 * Follow up: Could you solve it without loops/recursion?
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

class Solution {
public:
	//8ms,recursion
	bool isPowerOfFour(int num) {
		if (num == 1) {
			return true;
		}
		else {
			return !(num % 4) && isPowerOfFour(num / 4);
		}
	}
	//16ms,too slow
	bool isPowerOfFour1(int num) {
		unordered_set<int> s{ 4, 16, 64, 256, 1024, 4096, 16384, 65536, 262144, 
					1048576, 4194304, 16777216, 67108864, 268435456, 1073741824};
		if (s.find(num) != s.end())
			return true;
		return false;
	}
	//8ms
	bool isPowerOfFour2(int num) {
		if (num == 1)
			return true;
		else
			return (num % 10 == 4 || num % 10 == 6) && (num&(num - 1))==0;
	}
	//8ms
	bool isPowerOfFour3(int num) {
		return (num&(num - 1)) == 0 && ((num - 1) % 3) == 0;
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isPowerOfFour2(16) ? "true" : "false");
	system("pause");
	return 0;
}