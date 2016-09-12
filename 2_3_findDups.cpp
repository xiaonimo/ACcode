/* 2.2.长度为n的数组中，存在k(k<n)个数，每个数的数量都超过数组总元素数量的
 * 1/(K+1),找出这k个元素
 */
#include <iostream>
#include <sstream>
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
	//假设存在一个元素，他的个数超过数组元素总数的1/2，
	//第一种方法是排序，排序之后的N/2位置一定是该元素，事件复杂度o(n*logn)
	//第二种方法是遍历一次，“删除”数组中任意两个不同的元素，那么最后剩下的
	//一定是待查找的元素。（这里的删除不是真的删除，可以对这个元素进行标记）
	//第二种方法
	int findDup(vector<int> nums) {
		int res= nums[0];
		int cnt = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (res == nums[i])
				++cnt;
			else {
				if (cnt == 0) {
					res = nums[i];
					++cnt;
				}
				else
					--cnt;
			}
		}
		return res;
	}
	//假如数组中存在3个元素，每个元素的数量超过元素总数的1/4；
	vector<int> findDup1(vector<int> nums) {
		vector<int> res = { nums[0], nums[1], nums[2] };
		int cnt0 = 1, cnt1 = 1, cnt2 = 1;
		for (int i = 3; i < nums.size(); ++i) {
			if (nums[i] == res[0])
				++cnt0;
			else if (nums[i] == res[1])
				++cnt1;
			else if (nums[i] == res[2])
				++cnt2;
			else {
				if (0 == cnt0) {
					res[0] = nums[i];
					++cnt0;
				}
				else if (0 == cnt1) {
					res[1] = nums[i];
					++cnt1;
				}
				else if (0 == cnt2) {
					res[2] = nums[i];
					++cnt2;
				}
				else {
					--cnt0;
					--cnt1;
					--cnt2;
				}
			}
		}
		return res;
	}
	vector<int> findDup2(vector<int> nums) {
		vector<int> res = { nums[0], nums[1], nums[2] };
		vector<int> cnt = { 1, 1, 1 };
		for (int i = 3; i < nums.size(); ++i) {
			for (int j = 0; j < 3; ++j) {
				if (nums[i] == res[j]) {
					++cnt[j];
					continue;
				}
			}
			for (int j = 0; j < 3; ++j) {
				if (0 == cnt[j]) {
					res[j] == nums[i];
					++cnt[j];
					continue;
				}
			}
			for (int j = 0; j < 3; ++j) {
				--cnt[j];
			}
		}
		return res;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> arr = { 1, 2, 3, 1, 2, 4, 3, 1, 5, 2, 3 };
	vector<int> res = s.findDup2(arr);
	for (auto n : res)
		cout << n;
	system("pause");
	return 0;
}