/* Title:
* 移动窗口最大值
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size){
		if (num.empty())
			return num;
		if (size == 1)
			return num;
		deque<int> maxnum;
		deque<int> index;
		vector<int> res;
		for (unsigned i = 0; i < num.size(); ++i) {
			while (!maxnum.empty() && maxnum.back() < num[i]) {
				maxnum.pop_back();
				index.pop_back();
			}
			maxnum.push_back(num[i]);
			index.push_back(i);
			if ((i - index.front() + 1) > size) {
				maxnum.pop_front();
				index.pop_front();
			}
			if (i >= size - 1)
				res.push_back(maxnum.front());
		}
		return res;
	}
};

int main(int argc, char *argv[]) {
	Solution s;
	for (auto n : s.maxInWindows(vector<int>{2, 3, 4, 2, 6, 2, 5, 1}, 3))
		cout << n;

	system("pause");
	return 0;
}

