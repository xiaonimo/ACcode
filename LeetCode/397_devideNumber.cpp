/* Title:
 * Given a positive integer n and you can do operations as follow:
 * If n is even, replace n with n/2.
 * If n is odd, you can replace n with either n + 1 or n - 1.
 * What is the minimum number of replacements needed for n to become 1?

 * Example 1:
 * Input:8
 * Output:3
 * Explanation:
 * 8 -> 4 -> 2 -> 1
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>

using namespace std;

class Solution {
public:
	//0ms
	int integerReplacement(int n) {
		int cnt = 0;
		while (n != 1) {
			if (n == 1) return cnt;
			if (n == 3) return cnt + 2;
			if (n == INT_MAX) return 32;
			++cnt;
			if (n % 2 == 0) {
				n /= 2;
				continue;
			}
			if ((n + 1) % 4 == 0)
				n += 1;
			else
				n -= 1;
		}
		return cnt;
	}
};


int main(void)
{
	Solution s;
	cout << s.integerReplacement(INT_MAX);
	system("pause");
	return 0;
}
