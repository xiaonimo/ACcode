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
	//recursion.
	bool Find(vector<vector<int> > array, int target) {
		if (array.empty()) return false;
		int row = array.size(), col = array[0].size();
		return subFind(array, target, 0, 0);
		
	}
	bool subFind(vector<vector<int>> array, int target, int row, int col) {
		if (array[row][col] == target) return true;
		if (array[row][col] > target) return false;
		if (row == array.size() - 1 && col == array[0].size() - 1) return false;
		if (row == array.size() - 1)
			return subFind(array, target, row, col + 1);
		else if (col == array[0].size() - 1)
			return subFind(array, target, row + 1, col);
		return subFind(array, target, row + 1, col) || subFind(array, target, row, col + 1);
	}
	//binary search
	bool Find1(vector<vector<int> > array, int target) {
		if (array.empty()) return false;
		int row = array.size(), col = array[0].size();
		for (int i = 0; i < row; ++i) {
			if (target < array[i][0]) return false;
			if (array[i][0] <= target && target <= array[i][col - 1]
				&& binaryFind(array[i], target)) {
				return true;
			}
		}
		return false;
	}
	bool binaryFind(vector<int> nums, int target) {
		int low = 0, high = nums.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid] < target)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return false;
	}
	//O(M+N)
	bool Find3(vector<vector<int> > array, int target) {
		if (array.empty()) return false;
		int row = array.size(), col = array[0].size();
		for (int i = row-1, j = 0; i >= 0 && j < col;) {
			if (target == array[i][j])
				return true;
			else if (target < array[i][j]) {
				--i;
			}
			else {
				++j;
			}
		}
		return false;
	}
};

int main(void)
{
	Solution s;
	for (int i = 0; i < 120; ++i) {
		cout << s.Find3(vector<vector<int>>{{ 1, 2, 3,3 }, { 5, 5, 6 ,9}, { 7, 8, 9,18 }}, i);
	}
	system("pause");
	return 0;
}
