/* Given an array of integers, find if the array contains any duplicates. 
 * Your function should return true if any value appears at least twice in the array, 
 * and it should return false if every element is distinct.
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
	//set-52ms, slow.unordered_set 44ms
	bool containsDuplicate(vector<int>& nums) {
		//it is faster than set.
		unordered_set<int> s(nums.begin(), nums.end());
		return s.size() != nums.size();
	}
	//52ms
	bool containsDuplicate1(vector<int>& nums) {
		unordered_map<int, int> hmap;
		for (auto i : nums) {
			if (hmap.find(i) != hmap.end()) {
				return true;
			}
			else {
				++hmap[i];
			}
		}
		return false;
	}
	//40ms
	bool containsDuplicate2(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == nums[i - 1]) {
				return true;
			}
		}
		return false;
	}
};
int main()
{
	Solution s = Solution();
	int a[] = {6,5,5};
	vector<int> nums(a, a + sizeof(a) / sizeof(a[0]));
	cout << (s.containsDuplicate1(nums)?"true":"false") << endl;

	system("pause");
	return 0;
}