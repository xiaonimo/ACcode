/* Title:
* 回文链表
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Finder {
public:
	int findElement(vector<int> A, int n, int x) {
		// write code here
		int _low = 0;
		int _high = n - 1;
		while (_low <= _high) {
			int _mid = _low + (_high - _low) / 2;
			if (A[_mid] == x)
				return _mid;
			if (x > A[_mid]) {
				if (x > A[_low] && A[_mid] < A[_low])
					_high = _mid - 1;
				else
					_low = _mid + 1;
			}
			else {
				if (A[_mid] > A[_low] && x < A[_low])
					_low = _mid + 1;
				else
					_high = _mid - 1;
			}
		}
		return -1;
	}
};

int main(int argc, char *argv[]) {
	

	system("pause");
	return 0;
}

