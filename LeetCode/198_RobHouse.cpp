/* You are a professional robber planning to rob houses along a street.
* Each house has a certain amount of money stashed,
* the only constraint stopping you from robbing each of them is that
* adjacent houses have security system connected and it will automatically
* contact the police if two adjacent houses were broken into on the same night.

* Given a list of non-negative integers representing the amount of money
* of each house, determine the maximum amount of money you can rob tonight
* without alerting the police
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
	int rob(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int n = nums.size(), pre = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			int temp = max(pre + nums[i], cur);
			pre = cur;
			cur = temp;
		}
		return cur;
	}
	int rob1(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int sz = nums.size();
		vector<int> money(sz + 1, 0);
		money[1] = nums[0];
		for (int i = 2; i < sz+1; ++i) {
			money[i] = max(money[i - 1], money[i - 2] + nums[i-1]);
		}
		return money[sz];
	}
};

int main()
{
	Solution s = Solution();

	system("pause");
	return 0;
}