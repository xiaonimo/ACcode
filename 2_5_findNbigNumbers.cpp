/* 找到数组中最大的K个数
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
	//第一种方法，维护一个排好序queue，遍历数组。
};
//快速排序的代码，分而治之。
void quickSort(vector<int> &nums, int start, int end) {
	if (start >= end)
		return;
	int tmp = nums[start];
	int low = start;
	int high = end;
	
	while (low < high) {
		while (low < high && nums[high] >= tmp) --high;
		nums[low] = nums[high];
		while (low < high && nums[low] <= tmp) ++low;
		nums[high] = nums[low];
	}
	nums[low] = tmp;
	quickSort(nums, start, low-1);
	quickSort(nums, low + 1, end);
}
//插入排序，插入排序在对少量数据和基本排序的数组排序很快
//快速排序对大量数据和随机排序的数据排序效果好，所以可以对
//递归到一定程度的快速排序分组采用直接插入排序。
//从前往后比较，如果小于一个数就排在一个数的后面
void insertSort(vector<int> &nums) {
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < (int)nums.size(); ++i) {
		int index = 0;
		int tmp = nums[i];
		while (index < i && nums[i]>nums[index]) {
			++index;
		}
		int cur = i;
		while (cur != index) {
			nums[cur] = nums[cur-1];
			--cur;
		}
		nums[index] = tmp;
	}
}
//从后往前比较，如果大于一个数，就排在一个数的后面
//操作较为简化
void insertSort1(vector<int> &nums) {
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < (int)nums.size(); ++i) {
		if (nums[i]>=nums[i - 1])
			continue;
		int tmp = nums[i];
		int index = i-1;
		while (index >= 0 && tmp<nums[index]) {
			nums[index + 1] = nums[index];
			--index;
		}
		nums[index+1] = tmp;
	}
}
//二分插入排序，避免对所有已排序数字的比较
void insertSort2(vector<int> &nums) {
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < nums.size(); ++i) {
		int left = 0;
		int right = i - 1;
		int tmp = nums[i];
		int mid = 0;
		while (right>left) {
			mid = left + (right - left) / 2;
			if (nums[mid] < tmp) {
				left = mid + 1;
			}
			else if (nums[mid] > tmp){
				right = mid - 1;
			}
			else {
				break;
			}
		}
		for (int j = i - 1; j>left; --j) {
			nums[j + 1] = nums[j];
		}
		nums[left+1] = tmp;
	}
}
int main()
{
	Solution s = Solution();
	vector<int> vec = { 9, 8, 3, 4, 56, 23, 4, 65, 67, 67 };
	//quickSort(vec, 0, vec.size()-1);
	insertSort2(vec);
	for (auto num : vec)
		cout << num << endl;
	system("pause");
	return 0;
}