/* Reverse digits of an integer.

 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
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
	//12ms,
	int reverse(int x) {
		int res = 0, res_t = 0;
		int num = 0;
		bool flag = true;
		if (x < 0) {
			flag = false;
			x = -x;
		}
		while (x) {
			num = x % 10;
			res_t = res;
			res = res * 10 + num;
			if (((res - num)/10) != res_t) {
				res = 0;
				break;
			}
			x /= 10;
		}
		return flag?res:-res;
	}
	//8ms, simplify the code
	//another way is using a long long number to determine it's overflow or not.
	//but l thionk it's not good.
	int reverse1(int x) {
		int res = 0, res_t = 0;
		int num = 0;

		while (x) {
			num = x % 10;
			res_t = res;
			res = res * 10 + num;
			x /= 10;
		}
		return (res-num)/10 == res_t?res:0;
	}
};

int main()
{
	Solution s = Solution();
	cout << s.reverse1(-123);
	//cout << INT_MAX;

	system("pause");
	return 0;
}