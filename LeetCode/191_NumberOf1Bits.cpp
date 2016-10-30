/* Write a function that takes an unsigned integer 
 * and returns the number of ¡¯1' bits it has (also known as the Hamming weight).

 * For example, the 32-bit integer ¡¯11' has binary representation
 * 00000000000000000000000000001011, so the function should return 3.
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
	//8ms
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n) {
			if (n & 1) {
				++res;
			}
			n >>= 1;
		}
		return res;
	}
	//
	int hammingWeight1(uint32_t n) {
		int res = 0;
		while (n) {
			n &= n - 1;//delete the last 1
			++res;
		}
		return res;
	}
};

int main()
{
	Solution s = Solution();
	cout << s.hammingWeight(1024);
	system("pause");
	return 0;
}