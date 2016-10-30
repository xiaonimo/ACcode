/* Given an integer array nums, find the sum of the 
 * elements between indices i and j (i ≤ j), inclusive.

 * Example:
 * Given nums = [-2, 0, 3, -5, 2, -1]
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * Note:
 * You may assume that the array does not change.
 * There are many calls to sumRange function.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
#include <sstream>
using namespace std;
class NumArray {
private:
	vector<int> vec;
	vector<int> sumArray;
public:
	NumArray(vector<int> &nums) :vec(nums) {
		int sum = 0;
		for (int i = 0; i < (int)nums.size();++i) {
			sum += nums[i];
			sumArray[i] = sum;
		}
	}

	int sumRange(int i, int j) {
		return sumArray[j] - sumArray[i];
	}
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
int main()
{
	system("pause");
	return 0;
}