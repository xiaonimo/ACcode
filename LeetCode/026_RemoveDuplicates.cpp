/* Given a sorted array, remove the duplicates in place 
 * such that each element appear only once and return the new length.

 * Do not allocate extra space for another array, you must 
 * do this in place with constant memory.

 * For example,
 * Given input array nums = [1,1,2],

 * Your function should return length = 2, with the first two elements 
 * of nums being 1 and 2 respectively. It doesn't matter 
 * what you leave beyond the new length.
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
	//32ms,too complex.
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int pre = nums[0];
		int j = 1;
		for (auto i : nums) {
			if (i != pre) {
				nums[j++] = i;
				pre = i;
			}
		}
		return j;
	}
	//simplify
	int removeDuplicates1(vector<int>& nums) {
		int j = 0;
		for (auto i : nums) {
			if (!j || i != nums[j-1]) 
				nums[j++] = i;
		}
		return j;
	}
	//simplify
	int removeDuplicates2(vector<int>& nums) {
		int i = !nums.empty();
		for (auto n : nums) {
			if (n != nums[i - 1])
				nums[i++] = n;
		}
		return i;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}