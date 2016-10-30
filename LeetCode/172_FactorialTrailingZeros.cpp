/* Given an integer n, return the number of trailing zeroes in n!.

 * Note: Your solution should be in logarithmic time complexity.
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
	//4ms
	//0<n<5, f(n!)=0;
	//n>5,   f(n!)=(5k*5(k-1)....10*5)*a=5^k*K!=n/5+f(k!)
	//recursion
	int trailingZeroes(int n) {
		if (n < 5)
			return 0;
		return n/5 + trailingZeroes(n / 5);
	}
	//cost too much time
	//2*5=10, so f(n!)=count(5);
	int trailingZeroes1(int n) {
		int res = 0;
		for (int num = 5; num <= n; num+=5) {
			for (int i = num; (i%5==0)&&(i >= 5); i/=5) {
				++res;
			}
		}
		return res;
	}
	//while loop way; 
	int trailingZeroes(int n) {
		int count = 0;
		while (n /= 5) count += n;
		return count;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.trailingZeroes1(1808548329);
	system("pause");
	return 0;
}