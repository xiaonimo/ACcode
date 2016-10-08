/* 2.1
 * 求一个字节（8bit）无符号整型变量，二进制表现方式中1的个数。
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
	//o(n),n是数字二进制形式的位数
	int countBits0(int n) {
		int cnt = 0;
		while (n) {
			cnt += n & 0x1;
			n >>= 1;
		}
		return cnt;
	}
	//o(m)
	int countBits1(int n) {
		int cnt = 0;
		while (n) {
			n &= n - 1;
			++cnt;
		}
		return cnt;
	}
	//o(1),采用列举的办法，把每个数字中1的个数存入数组。
	//假设我们列举了所有的8位无符号整数，那么再求32无符号整数中
	//1的个数时，可以采用位操作和移位，按8位为一组计算1的个数。
	//典型的空间换时间做法。
	int countBits2(int n) {
		int list[256] = {};//列举8bit所有无符号整数中1的个数
		return list[(n)& 0xff] + list[(n >> 8) & 0xff] +
			list[(n >> 16) & 0xff] + list[(n >> 24) & 0xff];
	}
	//通过移位来巧妙的计算1的个数
	//假设n是32位整数，8bit整数也同理
	int countBits(int n) {
		n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
		return n;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.countBits0(34);
	system("pause");
	return 0;
}