/* Write a program to check whether a given number is an ugly number.

 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * For example, 6, 8 are ugly while 14 is not ugly since it includes another 
 * prime factor 7.

 * Note that 1 is typically treated as an ugly number.
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
	bool isUgly(int num) {
		if (num == 1 || num == 2 || num == 3 || num == 5) {
			return true;
		}
		else if (num <= 0) {
			return false;
		}
		else if (num % 2 == 0) {
			return isUgly(num / 2);
		}
		else if (num % 3 == 0) {
			return isUgly(num / 3);
		}
		else if (num % 5 == 0) {
			return isUgly(num / 5);
		}
		else {
			return false;
		}
	}
	//8ms, another way like first function
	bool isUgly1(int num) {
		if (num <= 0) {
			return false;
		}
		while (num != 1) {
			if (num % 2 == 0) {
				num /= 2;
			}
			else if (num % 3 == 0) {
				num /= 3;
			}
			else if (num % 5 == 0) {
				num /= 5;
			}
			else {
				return false;
			}
		}
		return true;
	}
	//short and clean
	bool isUgly2(int num) {
		if (num <= 0) {
			return false;
		}
		while (num % 2 == 0) {
			num /= 2;
		}
		while (num % 3 == 0) {
			num /= 3;
		}
		while (num % 5 == 0) {
			num /= 5;
		}
		return num == 1;
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isUgly1(20) ? "true" : "false") << endl;
	
	system("pause");
	return 0;
}