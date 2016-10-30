/* Given an array of integers and an integer k, 
 * find out whether there are two distinct indices i and j 
 * in the array such that nums[i] = nums[j] and the 
 * difference between i and j is at most k.
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
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int> hnums;
		for (int i = 0; i < (int)nums.size(); ++i) {
			if (hnums[nums[i]] && i - hnums[nums[i]] + 1 <= k)
				return true;
			hnums[nums[i]] = i + 1;
		}
		return false;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}