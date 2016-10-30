/* You are climbing a stair case. It takes n steps to reach to the top.

 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	// In fact it's a fabonacci problem!easy.
	int climbStairs(int n) {
		if (n <= 2) {
			return n;
		}
		int f1 = 1, f2 = 2;
		int sum = 0;
		for (int i = 2; i < n; ++i) {
			sum = f1 + f2;
			f1 = f2;
			f2 = sum;
		}
		return sum;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.climbStairs(44);
	system("pause");
	return 0;
}