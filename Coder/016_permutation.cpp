/* Title:
* permutation
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Permutation {
public:
	vector<string> getPermutation(string A) {
		// write code here
		vector<string> res;
		if (A.size() <= 1) {
			res.push_back(A);
			return res;
		}
		for (unsigned i = 0; i<A.size(); ++i) {
			swap(A[0], A[i]);
			vector<string> sub_res = getPermutation(string(begin(A) + 1, end(A)));
			for (auto str : sub_res) {
				res.push_back(A[0] + str);
			}
			swap(A[0], A[i]);
		}
		sort(begin(res), end(res));
		return res;
	}

	//减少生成的中间对象
	vector<string> getPermutation1(string A) {
		if (A.size() <= 1)
			return vector<string>{A};
		vector<string> res;
		myPermu(res, A, 0);
		return res;
	}
	void myPermu(vector<string>& res, string A, int cur) {
		if (cur == A.size() - 1) {
			res.push_back(A);
			return;
		}
		for (unsigned i = cur; i < A.size(); ++i) {
			swap(A[cur], A[i]);
			myPermu(res, A, cur+1);
			swap(A[cur], A[i]);
		}
	}
};

int main(int argc, char *argv[]) {


	system("pause");
	return 0;
}

