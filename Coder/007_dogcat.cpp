/* Title:
* cat and dog
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class CatDogAsylum {
public:
	vector<int> asylum(vector<vector<int> > ope) {
		// write code here
		int _time_stamp = 0;
		queue<pair<int, int>> qdog;
		queue<pair<int, int>> qcat;
		vector<int> res;

		for (auto vec : ope) {
			if (vec[0] == 1) {
				if (vec[1] > 0) {
					qdog.push(make_pair(vec[1], _time_stamp++));
				}
				else {
					qcat.push(make_pair(vec[1], _time_stamp++));
				}
			}
			if (vec[0] == 2) {
				if (qdog.empty() && qcat.empty())
					continue;
				if (vec[1] == 0) {
					if (qcat.empty()) {
						res.push_back(qdog.front().first);
						qdog.pop();
					}
					else if (qdog.empty()) {
						res.push_back(qcat.front().first);
						qcat.pop();
					}
					else if (qdog.front().second < qcat.front().second) {
						res.push_back(qdog.front().first);
						qdog.pop();
					}
					else {
						res.push_back(qcat.front().first);
						qcat.pop();
					}
				}
				else if (vec[1] == 1 && !qdog.empty()) {
					res.push_back(qdog.front().first);
					qdog.pop();
				}
				else if (vec[1] == -1 && !qcat.empty()) {
					res.push_back(qcat.front().first);
					qcat.pop();
				}
				else {
					;
				}
			}
		}
		return res;
	}
};
int main(int argc, char *argv[]) {
	CatDogAsylum s;
	for (auto v : s.asylum(vector<vector<int>>{{ 1, 1 }, { 1, -1 }, { 2, 0 }, { 2, -1 }}))
		cout << v << endl;

	system("pause");
	return 0;
}

