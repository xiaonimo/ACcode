/* Given two arrays, write a function to compute their intersection.

 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

 * Note:
 * Each element in the result should appear as many times as it shows in both arrays.
 * The result can be in any order.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	//12ms
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> hmap;
		for (auto i : nums1) {
			++hmap[i];
		}
		for (auto i : nums2) {
			if (--hmap[i] >= 0) {//hamp[i] is set default as 0. 
				res.push_back(i);
			}
		}
		return res;
	}

	//8ms
	vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				++i;
				++j;
			}
			else if (nums1[i] > nums2[j]) {
				++j;
			}
			else {
				++i;
			}
		}
		return res;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> nums1 = { 1, 2, 2, 1 };
	vector<int> nums2 = { 2, 2 };
	vector<int> set1;
	set1 = s.intersect1(nums1, nums2);
	for (auto i : set1)
		cout << i << endl;

	system("pause");
	return 0;
}