﻿/* Given an array and a value, remove all instances of that value in place 
 * and return the new length.
 * Do not allocate extra space for another array, you must do this in place 
 * with constant memory.

 * The order of elements can be changed. It doesn't matter what you leave 
 * beyond the new length.

 * Example:
 * Given input array nums = [3,2,2,3], val = 3

 * Your function should return length = 2, with the first two elements of nums being 2.
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
	//4ms,O(n)
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		for (auto num : nums) {
			if (num != val)
				nums[i++] = num;
		}
		return i;
	}
};

int main()
{
	Solution s = Solution();
	vector<int> a{3,2,2,3};
	cout << s.removeElement(a, 3) << endl;
	for (auto i : a) {
		cout << i;
	}
	system("pause");
	return 0;
}