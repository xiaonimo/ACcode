/**Title:
 * use two stacks to implement queue.pop and queue.push
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
	//in order
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;
		if (rotateArray.size() == 1) return rotateArray[0];
		for (int i = 1; i < (int)rotateArray.size(); ++i) {
			if (rotateArray[i] < rotateArray[i - 1])
				return rotateArray[i];
		}
		return rotateArray[0];
	}
	//mid find,但是这种方法不能处理{1,1,0,1}这种情况，只能调用上述的顺序查找办法
	int minNumberInRotateArray1(vector<int> rotateArray) {
		if (rotateArray.empty()) return 0;
		if (rotateArray.size() == 1) return rotateArray[0];
		int left = 0, right = (int)rotateArray.size()-1;
		int mid = left + (right - left) / 2;
		while (left < right) {
			if (rotateArray[left] < rotateArray[mid])
				left = mid;
			else if (rotateArray[left] == rotateArray[mid]
				&& rotateArray[left] == rotateArray[right])
				return minNumberInRotateArray(rotateArray);
			else
				right = mid;
			mid = left + (right - left) / 2;
		}
		return rotateArray[mid + 1];
	}
};

int main(void)
{
	Solution s;
	cout << s.minNumberInRotateArray1(vector<int>{1, 1, 0, 1});
	system("pause");
	return 0;
}
