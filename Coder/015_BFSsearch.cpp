/* Title:
* 回文链表
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Flood {
public:
	//单向BFS搜索
	int floodFill(vector<vector<int> > map, int n, int m) {
		vector<pair<int, int>> pos{ make_pair(0, -1), make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0)};
		int x1 = 0, y1 = 0;
		int step1 = 0;
		queue<pair<int, int>> q1;
		q1.push(make_pair(0, 0));
		while (1) {
			int sz1 = q1.size();
			for (unsigned i = 0; i<sz1; ++i) {
				auto p = q1.front();
				if (p.first == n-1 && p.second == m-1)
					return step1;
				map[p.first][p.second] = 1;
				++step1;
				for (auto pp : pos) {
					int xt = p.first + pp.first;
					int yt = p.second + pp.second;
					if (_isLegal(map, xt, yt, n, m))
						q1.push(make_pair(xt, yt));
				}
			}
		}
		return step1;
	}
	bool _isLegal(vector<vector<int>> map, int x, int y, int n, int m) {
		if (x < 0 || x >= n || y< 0 || y >= m || map[x][y])
			return false;
		return true;
	}
};

int main(int argc, char *argv[]) {


	system("pause");
	return 0;
}

