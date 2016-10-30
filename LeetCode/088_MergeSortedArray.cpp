/* Given two sorted integer arrays nums1 and nums2,
 * merge nums2 into nums1 as one sorted array.
 * Note:
 * You may assume that nums1 has enough space (size that is
 * greater or equal to m + n) to hold additional elements from nums2.
 * The number of elements initialized in nums1 and nums2 are m and n respectively.
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
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int j = 0;
		int i1 = 0, i2 = 0;
		vector<int> tnums1(nums1);
		while (j < m + n) {
			if ((i1 < m) && (i2 >= n || tnums1[i1] <= nums2[i2])) {
				nums1[j++] = tnums1[i1++];
			}
			else {
				nums1[j++] = nums2[i2++];
			}
		}
	}
	//another simple idea.
	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i1 = m - 1, i2 = n - 1, sz = m + n - 1; i2 >= 0;)
			nums1[sz--] = nums1[i1] > nums2[i2] ? nums1[i1--] : nums2[i2--];
	}
};

int main()
{
	Solution s = Solution();
	vector<int> a{ 1, 2, 5, 0, 0, 0, 0 };
	vector<int> b{ 2, 5, 8, 9 };
	s.merge(a, 3, b, 4);
	for (auto i : a)
		cout << i;
	system("pause");
	return 0;
}