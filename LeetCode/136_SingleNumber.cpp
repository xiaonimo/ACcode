/* Given an array of integers, every element appears 
 * twice except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
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
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (auto c : nums)
			res ^= c;
		return res;
	}
};

int main()
{
	Solution s = Solution();
	
	cout << (char)('a'^'b'^'a');
	system("pause");
	return 0;
}