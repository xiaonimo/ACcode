/* 求从1开始的连续n个自然数中，所有数位上1出现的次数
 * 1:1
 * 1,2:1
 * 1,2,3....9,10,11:4
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
	//第一种方法，想法很简单，就是遍历n个数，找出每个数n所有数位中的1的个数
	int OneNumbers(int n) {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			cnt += OneNumbersInInterger(i);
		}
		return cnt;
	}
	int OneNumbersInInterger(int n) {
		int cnt = 0;
		while (n) {
			if (1 == n % 10)
				++cnt;
			n /= 10;
		}
		return cnt;
	}
	/*根据题意，可以知道，一旦最终的数字N给定，那么之前的数字数列已经确定，
	 *所以1的个数也确定，那我们是不是可以在N这个数字上做一些文章呢？
	 *一个数位上的数字可以分为，0,1和大于1的三类数。
	 *如果是0，那么该位上可以出现1的次数由更高位决定。如102，那么十位上出现1的个数是1*10；
	 *分别是10,11,12,13...19。1表示0之前的数字，10表示当前位的进制。（由于只是计算该位置出现1
	 *的次数，所以11只记录十位的1，并不记录各位的1）
	 
	 *如果数位是1，那么该数位上出现1的次数由其之前的数字和其之后的数字共同决定。
	 *比如112，十位上的数字是1，那么1的个数是1*10+2,1是该位之前的数字，10是该位的进制
	 *2是该位之后的数字。
	 
	 *如果是大于1的数，那么该位置出现1的次数由该位之前的数字决定，
	 *如121，那么十位出现1的个数是，1*10 + 1*10
	 *分别是10,11...19,110,111.....119.
	 */
	int OneNumbers1(int n) {
		int cnt = 0;
		int curNum = 0;
		int curRat = 1;
		int backNum = 0;
		int frontNum = 0;
		while (0 != n/curRat) {
			curNum = (n/curRat) % 10;
			backNum = n - (n / curRat)*curRat;
			frontNum = n / (curRat*10);
			if (0 == curNum) {
				cnt += curRat*frontNum;
			}
			else if (1 == curNum) {
				cnt += curRat*frontNum + backNum + 1;
			}
			else {
				cnt += curRat*(frontNum + 1);
			}
			curRat *= 10;
		}
		return cnt;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.OneNumbers(12);
	system("pause");
	return 0;
}