/**Title:
 * Top K Frequent Elements
 * Given a non-empty array of integers, return the k most frequent elements.

 * For example,
 * Given [1,1,1,2,2,3] and k = 2, return [1,2].
 * Note:
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), 
 * where n is the array's size.
 */
#include<iostream>  
#include<vector>
#include<algorithm>
#define F(X,Y)   (X)--, (Y)++, (X)*(Y);
using namespace std;
class Solution {
public:
	//usse sort
	vector<int> topKFrequent1(vector<int>& nums, int k) {
		if (nums.empty()) return nums;
		vector<int> res;
		if (k <= 0) return res;
		sort(begin(nums), end(nums));
		int sz = nums.size();
	}
};

//大顶堆
class _max_heap {
private:
	vector<int> arr;

	void _max_heap_fixup(int beg, int last);
	void _max_heap_fixdown(int beg, int last);
	void _max_heap_init();
public:
	_max_heap(vector<int> t) :arr(t) {
		_max_heap_init();
	}
	void _max_heap_add(int x);
	void _max_heap_delete();
	void _max_heap_sort();
	void print() {
		for (auto num : arr)
			cout << num << '\t';
		cout << endl;
	}
};
void _max_heap::_max_heap_fixup(int beg, int last) {
	if (last - beg <= 1) return;

	int tmp = arr[beg];

	int i = beg, j = 2 * i + 1;
	while (j <= last) {
		if (j + 1 <= last && arr[j] < arr[j + 1])
			++j;
		if (tmp>arr[j])
			break;
		arr[i] = arr[j];
		i = j;
		j = 2 * i + 1;
	}
	arr[i] = tmp;
}
void _max_heap::_max_heap_fixdown(int beg, int last) {
	if (last - beg <= 1) return;

	int tmp = arr[last];

	int i = last, j = (i - 1) / 2;
	while (i >= 0) {
		if (tmp < arr[j])
			break;
		arr[i] = arr[j];
		i = j;
		j = (i - 1) / 2;
	}
	arr[i] = tmp;
}
void _max_heap::_max_heap_add(int x) {
	arr.push_back(x);//if succeed to push_back;
	_max_heap_fixdown(0, arr.size()-1);
}
void _max_heap::_max_heap_delete() {
	if (arr.empty()) return;
	int tmp = arr[arr.size() - 1];
	arr[0] = tmp;
	arr.pop_back();
	_max_heap_fixup(0, arr.size()-1);
}
void _max_heap::_max_heap_sort() {
	int sz = arr.size();
	for (int i = 0; i < sz; ++i) {
		swap(arr[0], arr[sz - 1 - i]);
		_max_heap_fixup(0, sz - i - 2);
	}
}
void _max_heap::_max_heap_init() {
	int sz = arr.size();
	for (int i = (sz - 2) / 2; i >= 0; --i) {
		_max_heap_fixup(i, sz - 1);
	}
}
int main(void)
{
	_max_heap a = _max_heap(vector<int>{1, 4, 5, 2, 6, 7, 3, 9});
	a.print();
	a._max_heap_sort();
	a.print();
	system("pause");
	return 0;
}
