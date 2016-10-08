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
	/*方法1：
	*对全部的数组排序，那么意味着前K个元素和其他N-K个元素
	*都是排序的。复杂度是O(N*logN),方法略。
	*/
	/*方法2：
	*维护一个排好序的小数组(K)，遍历大数组(N)。
	*在遍历数组过程中，不断的更新小数组(其实是一种插入排序)。
	*跟第一种方法比较只有K个元素需要排序。
	*复杂度是O(N*K)
	*/
	/*方法3：
	*是根据快速排序。得到一部分最大数，根据这部分最大的数求解
	*K个最大的数。对所有元素都不需要排序。
	*/
	void Knumbers(vector<int> &nums, int first, int last, int k) {
		if (k >= last - first + 1)
			return;
		int i = first, j = last;
		int tmp = nums[first];
		while (i < j) {
			while (i<j && nums[j] <= tmp) --j;
			nums[i] = nums[j];
			while (i<j && nums[i] >= tmp) ++i;
			nums[j] = nums[i];
		}
		nums[i] = tmp;
		if (i - first + 1 >= k)
			Knumbers(nums, first, i, k);
		//注意，这里用first和last，不要用0或者nums.size()-1表示数组开始或者结束下标
		else
			Knumbers(nums, i + 1, last, k - (i - first + 1));
		return;
	}
	/*方法4：
	*求解数列中第k大数，那么这个数以及大于这个数的元素都的集合是问题的解。
	*求第K大数的方法可以由快排演化而来，在getKthNumber函数中实现
	*/
	/*方法5：
	*堆排序，待续。
	*
	*/
};
/*快速排序
*分而治之
*/
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
	quickSort(nums, start, low - 1);
	quickSort(nums, low + 1, end);
}

/*插入排序
*插入排序在对少量数据和基本排序的数组排序很快
*快速排序对大量数据和随机排序的数据排序效果好，所以可以对
*递归到一定程度的快速排序分组采用直接插入排序。
*/

/*方法1：
*从前往后比较，如果小于一个数就排在一个数的前面
*/
void insertSort0(vector<int> &nums) {
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
			nums[cur] = nums[cur - 1];
			--cur;
		}
		nums[index] = tmp;
	}
}
/*方法2：
*从后往前比较，如果大于一个数，就排在一个数的后面
*查找操作和移位操作合并 到一个循环
*/
void insertSort1(vector<int> &nums) {
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < (int)nums.size(); ++i) {
		if (nums[i] >= nums[i - 1])
			continue;
		int tmp = nums[i];
		int index = i - 1;
		while (index >= 0 && tmp<nums[index]) {
			nums[index + 1] = nums[index];
			--index;
		}
		nums[index + 1] = tmp;
	}
}
/*方法3：
*二分插入排序，避免对所有已排序数字的比较
*如代码所示，最终的二分查找结果，right+1==left
*如果right==left，那么一些情况不能处理。
*/
void insertSort2(vector<int> &nums) {
	if (nums.size() <= 1)
		return;
	for (int i = 1; i < (int)nums.size(); ++i) {
		int left = 0;
		int right = i - 1;
		int tmp = nums[i];
		int mid = 0;
		while (right >= left) {
			mid = left + (right - left) / 2;
			if (nums[mid] >= tmp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for (int j = i - 1; j>right; --j) {
			nums[j + 1] = nums[j];
		}
		nums[right + 1] = tmp;
	}
}
/*查找第K大数
*利用快排衍生的算法
*/
int getKthNumber(vector<int> nums, int first, int last, int k) {
	if (k > last - first + 1)
		//=这里不能使用等号，因为这个数据段是没有排序的。
		return nums[last];
	int i = first, j = last;
	int tmp = nums[first];
	while (i < j) {
		while (i < j && nums[j] <= tmp) --j;
		nums[i] = nums[j];
		while (i < j && nums[i] >= tmp) ++i;
		nums[j] = nums[i];
	}
	nums[i] = tmp;
	if (k == i - first + 1)
		return nums[i];
	else if (k>i - first + 1)
		return getKthNumber(nums, i + 1, last, k - (i - first + 1));
	else
		return getKthNumber(nums, first, i - 1, k);
}
int main()
{
	Solution s = Solution();
	vector<int> vec = { 9, 8, 3, 9, 56, 23, 4, 65, 67, 66 };
	for (int i = 0; i < 10; ++i) {
		cout << getKthNumber(vec, 0, vec.size() - 1, i + 1) << endl;
	}
	system("pause");
	return 0;
}