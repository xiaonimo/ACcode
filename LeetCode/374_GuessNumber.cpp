/* We are playing the Guess Game. The game is as follows:
 * I pick a number from 1 to n. You have to guess which number I picked.
 * Every time you guess wrong, I'll tell you whether the number is higher or lower.

 * You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

 * -1 : My number is lower
 *	1 : My number is higher
 *	0 : Congrats! You got it!
 * 
 * Example:
 * n = 10, I pick 6.
 * Return 6.
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

int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int l = 1;
		long long h = (long long)n + 1;
		int m = (h + l) / 2;
		while (guess(m) != 0) {
			if (guess(m) == -1)
				h = m - 1;
			else
				l = m + 1;
			m = (h + l) / 2;
		}
		return int(m);
	}
};

int main()
{
	Solution s = Solution();
	cout << s.guessNumber(2147483647);
	system("pause");
	return 0;
}