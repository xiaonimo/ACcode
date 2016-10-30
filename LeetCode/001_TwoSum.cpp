/* Given an array of integers, return indices of the 
 * two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
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
class Solution {
public:
	//25ms
	//use sort is not a good solution,because as you sort the vector,the index is mixed
	// so you need to o(n) space to store the raw vectors to restore the index.
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hmap;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			int index = hmap[target - nums[i]];
			if (index) {
				res.push_back(index-1);
				res.push_back(i);
			}
			hmap[nums[i]] = i + 1;
		}
		return res;
	}

};
int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}