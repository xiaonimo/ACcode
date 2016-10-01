/* Title:
 * The max sum of the array
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
	//动态规划
	//sum是当前子数组中最大子数组和
	int getMaxSum(vector<int> nums) {
		int sz = nums.size();
		int sum = nums[sz - 1];
		int beg = nums[sz - 1];
		for (int i = sz - 2; i >= 0; --i) {
			beg = max(nums[i], nums[i] + beg);
			sum = max(sum, beg);
		}
		return sum;
	}
	//最小子数组,原理基本相同
	int minArraySum(vector<int> nums) {
		if (nums.empty()) return 0;
		int min_sum = nums[0];
		int min_end_here = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			min_end_here = min(nums[i], nums[i] + min_end_here);
			min_sum = min(min_sum, min_end_here);
		}
		return min_sum;
	}
};

int main(void)
{
	Solution s;
	cout << s.getMaxSum(vector<int>{-9, -2, -3, -5, -3});
	system("pause");
	return 0;
}
