/* Title:
 * Single num III
 * Given an array of numbers nums, in which exactly two elements 
 * appear only once and all the other elements appear exactly twice. 
 * Find the two elements that appear only once.

 * For example:
 * Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
 * Note:
 * The order of the result is not important. 
 * So in the above example, [5, 3] is also correct.
 * Your algorithm should run in linear runtime complexity. 
 * Could you implement it using only constant space complexity?
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
	//use sort O(n*logn)
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res;
		sort(begin(nums), end(nums));
		int beg = 1, last = nums.size();
		while(beg<last) {
			if (nums[beg] == nums[beg - 1]) beg += 2;
			else {
				res.push_back(nums[beg - 1]);
				++beg;
			}
		}
		if (res.size() == 1)
			res.push_back(nums[nums.size() - 1]);
		return res;
	}
	//use bit operation, O(N)
	vector<int> singleNumber1(vector<int>& nums) {
		vector<int> res(2, 0);
		int numsxor = 0;
		for (auto num : nums)
			numsxor ^= num;
		numsxor &= -numsxor;//这是为了获得最后一个set位，证明方法需要从原码，反码，补码的关系得到
		for (auto num : nums) {
			if ((num & numsxor) == 0)
				res[0] ^= num;
			else
				res[1] ^= num;
		}
		return res;
	}
};

int main(void)
{
	cout << (1 << 3 + 2);
	system("pause");
	return 0;
}
