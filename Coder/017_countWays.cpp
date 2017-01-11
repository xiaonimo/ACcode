/* Title:
* 回文链表
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Robot {
public:
	//BFS搜索
	int countWays(vector<vector<int>> map, int x, int y) {
		// write code here
		vector<vector<int>> pos{ { 0, 1 }, { 1, 0 }};
		int res = 0;
		queue<vector<int>> que;
		que.push(vector<int>{0,0});
		while (!que.empty()) {
			unsigned sz = que.size();
			for (unsigned i = 0; i < sz; ++i) {
				vector<int> p = que.front();
				que.pop();
				if (p[0] == (x - 1) && p[1] == (y - 1))
					++res;
				for (auto pp : pos) {
					int tx = p[0] + pp[0];
					int ty = p[1] + pp[1];
					if (_isLegal(map, x, y, tx, ty))
						que.push(vector<int>{tx, ty});
				}
			}
		}
		return res;
	}
	bool _isLegal(vector<vector<int>> map, int x, int y, int i, int j) {
		if (i < 0 || i >= x || j < 0 || j >= y || !map[i][j])
			return false;
		return true;
	}

	//DFS搜索
	int countWays1(vector<vector<int>> map, int x, int y) {
		int res = 0;
		_count(map, x, y, 0, 0, res);
		return res;
	}
	void _count(vector<vector<int>> map, int x, int y, int i, int j, int& res) {
		if (i < 0 || i >= x || j < 0 || j >= y || !map[i][j])
			return;
		if (i == (x - 1) && j == (y - 1)) {
			++res;
			return;
		}
		_count(map, x, y, i + 1, j, res);
		_count(map, x, y, i, j + 1, res);
	}

	//DP
	int countWays(vector<vector<int> > map, int x, int y) {
		vector<vector<int> > f(x, vector<int>(y, 0));
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (map[i][j] == 0)f[i][j] = 0; // 不能走，就是方法数==0
				else if (i == 0 && j == 0)f[i][j] = 1; // 起点，1种走法
				else if (i == 0 && j != 0)f[i][j] = f[i][j - 1]; // 上边沿：只能从左边来
				else if (i != 0 && j == 0)f[i][j] = f[i - 1][j]; // 左边沿：只能从上边来
				else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % 1000000007; // 其他点：左边+上边
			}
		}
		return f[x - 1][y - 1];
	}
};
int main(int argc, char *argv[]) {
	Robot s;
	cout << s.countWays1(vector<vector<int>>{{ 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 0, 1, 1 },
	{ 0, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }}, 11, 4);

	system("pause");
	return 0;
}

