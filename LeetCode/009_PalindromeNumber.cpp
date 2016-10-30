/* Determine whether an integer is a palindrome. Do this without extra space.
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
	//there will be overflow , but it doesn't affect the outcome.
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int xt = x;
		int p = 0;
		while (x) {
			int digit = x % 10;
			p = p * 10 + digit;
			x /= 10;
		}
		return xt == p ? true : false;
	}
	bool isPalindrome1(int x) {
		if (x < 0 || (!x && (x % 10 == 0)))
			return false;
		int y = 0;
		while (x>y) {
			y = y * 10 + x % 10;
			x /= 10;
		}
		cout << x << endl << y;
		return (x == y) || (x == (y / 10));
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isPalindrome1(0) ? "true" : "false");
	system("pause");
	return 0;
}