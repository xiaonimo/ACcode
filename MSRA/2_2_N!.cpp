/* 2.2.阶乘N!
 * 求N!，10进制数末尾0的个数，二进制表示方法中末尾零的个数
 * 第二问也可以说是二进数末尾1的位置。
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
	//一个阶乘中0的个数取决于阶乘过程中有多少10相乘
	//假设阶乘结果是Z，那么，Z = 2^x*3^y*5^z......
	//只有2*5=10，而且x>z,所以问题的答案只取决于5的个数
	//笨方法是从5开始，做for循环，计算5~N中，每个数分别能贡献多少个5，
	//一种简单的方法是，通过N计算，N表示目前从1~N共有N个数连续相乘，
	//那么，以5为间距，就会出现一个5的倍数。。但是考虑25，这个数字提供
	//两个5，所以可以认为在25的间距上的每个数字会提供两个5.125间距上的数字会提供3个5；
	//loop
	int CountZeros(int n) {
		int cnt = 0;
		while (n) {
			n /= 5;
			cnt += n;
		}
		return cnt;
	}
	//recursion
	int CountZeros1(int n) {
		if (n < 5)
			return 0;
		return n / 5 + CountZeros1(n / 5);
	}
	//计算N!二进制结果中末尾0的个数。如果一个数字的末尾产生0，那么一定是因为乘以2，导致
	//原有数字向左移1位。假设结果是Z，那么Z=2^X*(奇数)。一个二进数n乘上一个奇数2k+1，可以化为
	//2kn+n,2kn使得n向左移动2k位，但是加上n会使得结果的末尾的0的个数和原来相同。所以只有2才能影响
	//结果，求N!中2的个数，和求5的个数原理相同。
	int TrailingZeros(int n) {
		int cnt = 0;
		while (n) {
			n >>= 1;
			cnt += n;
		}
		return cnt;
	}
	//计算一个数是不是2的幂次，使用(n>0 && 0==n&(n-1))
};
int main()
{
	Solution s = Solution();

	system("pause");
	return 0;
}