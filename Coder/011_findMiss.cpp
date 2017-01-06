/* Title:
* cat and dog
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Finder {
public:
	//二分法
	int findMissing(vector<vector<int> > numbers, int n) {
		// write code here
		int low = 0, high = numbers.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (numbers[mid][0] == (mid & 1))
				low = mid + 1;
			else
				high = mid - 1;
		}
		return low == numbers.size() ? n : low;
	}
	//最后一位是0,1交替的
	int findmiss(vector<vector<int>> numbers, int n) {
		for (int i = 0; i < n; ++i) {
			if ((i & 1) == numbers[i][0])
				return i;
		}
		return n;
	}
};

int main(int argc, char *argv[]) {
	BinInsert s;
	for (auto c : s.printBin(0.255))
		cout << c;
	system("pause");
	return 0;
}

