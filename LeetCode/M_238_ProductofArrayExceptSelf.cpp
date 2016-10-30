/* Title:
 * Given an array of n integers where n > 1, nums, 
 * return an array output such that output[i] is equal 
 * to the product of all the elements of nums except nums[i].
 * Solve it without division and in O(n).
 * 
 * Example:
 * given [1,2,3,4], return [24,12,8,6].
 * Follow up:
 * Could you solve it with constant space complexity? 
 * Note: 
 * The output array does not count as extra space 
 * for the purpose of space complexity analysis.)
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>

using namespace std;

class Solution {
public:
	//O(n)time,O(n)space
	vector<int> productExceptSelf(vector<int>& nums) {
		if (nums.empty()) return nums;
		int sz = nums.size();
		vector<int> begin_production(sz, 1), end_production(sz, 1);
		vector<int> res(sz, 1);
		for (int i = 1; i < sz; ++i) {
			begin_production[i] = begin_production[i - 1] * nums[i - 1];
			end_production[sz - i - 1] = end_production[sz - i] * nums[sz - i];
		}
		for (int i = 0; i < sz; ++i) {
			res[i] = begin_production[i] * end_production[i];
		}
		return res;
	}
	//O(n)time, O(1)space
	vector<int> productExceptSelf1(vector<int>& nums) {
		if (nums.empty()) return nums;
		int sz = nums.size();
		vector<int> res(sz, 1);
		int beg = 1, last = 1;
		for (int i = 0; i < sz; ++i) {
			res[i] *= beg;
			beg *= nums[i];
			res[sz - 1 - i] *= last;
			last *= nums[sz - i - 1];
		}
		return res;
	}
};


int main(void)
{
	Solution s;


	system("pause");
	return 0;
}
