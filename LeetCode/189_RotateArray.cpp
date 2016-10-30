/* Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
 * is rotated to [5,6,7,1,2,3,4].
 * Note:
 * Try to come up as many solutions as you can, 
 * there are at least 3 different ways to solve this problem.
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
	//24ms
	void rotate(vector<int>& nums, int k) {
		vector<int> nt(nums);
		auto sz = nums.size();
		for (decltype(sz) i = 0; i < sz; ++i) {
			//nums[i] = nt[(i + sz - (k%sz)) % sz];
			nums[(i + k) % sz] = nt[i];
		}
	}
	void rotate1(vector<int>& nums, int k) {
		k = k%nums.size();
		reverse(begin(nums),end(nums) - k);
		reverse(end(nums)-k,end(nums));
		reverse(begin(nums),end(nums));
	}
	//Another Way.
	// Swap the last k elements with the first k elements. 
	// The last k elements will be in the correct positions
	// but we need to rotate the remaining (n - k) elements 
	// to the right by k steps.
};
int main()
{
	vector<int> a{ 1, 2, 3, 4, 5, 6, 7 };
	Solution s = Solution();
	s.rotate1(a, 3);
	for (auto i : a)
		cout << i;
	system("pause");
	return 0;
}