/* Reverse bits of a given 32 bits unsigned integer.

 * For example, given input 43261596 (represented in binary as 
 * 00000010100101000001111010011100), return 964176192 
 * (represented in binary as 00111001011110000010100101000000).

 * Follow up:
 * If this function is called many times, how would you optimize it?
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <sstream>
using namespace std;
typedef unsigned int uint32_t;
class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t res = 0;
		uint32_t opr = 1;
		for (int i = 0; i < 32; ++i) {
			res <<= 1;
			if (n & opr)
				++res;
			opr <<= 1;
		}
		return res;
	}
	//good way
	uint32_t reverseBits(uint32_t n) {
		n = (n >> 16) | (n << 16);
		n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
		n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
		n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
		n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
		return n;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.reverseBits(1);
	system("pause");
	return 0;
}