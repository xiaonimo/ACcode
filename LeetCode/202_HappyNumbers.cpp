/* Write an algorithm to determine if a number is "happy".

 * A happy number is a number defined by the following process: 
 * Starting with any positive integer, replace the number 
 * by the sum of the squares of its digits, and repeat the process 
 * until the number equals 1 (where it will stay), 
 * or it loops endlessly in a cycle which does not include 1. 
 * Those numbers for which this process ends in 1 are happy numbers.

 * Example: 19 is a happy number

 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
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
typedef unsigned int uint32_t;
class Solution {
public:
	//4ms, how to prove that there is always a 4 in the cycle on interview?
	bool isHappy(int n) {
		if (1 == n) {
			return true;
		}
		else if (4 == n) {
			return false;
		}
		else {
			int sum = 0;
			while (n){
				sum += pow(n % 10, 2);
				n /= 10;
			}
			return isHappy(sum);
		}
	}
	//8ms,There must be a cycle.
	bool isHappy1(int n) {
		unordered_set<int> s;
		while (n != 1) {
			if (s.find(n) != s.end()) {
				return false;
			}
			s.insert(n);
			int sum = 0;
			while (n) {
				sum += pow(n % 10, 2);
				n /= 10;
			}
			n = sum;
		}
		return true;
	}
};

int main()
{
	Solution s = Solution();
	cout << (s.isHappy(19) ? "true" : "false") << endl;

	system("pause");
	return 0;
}