/* Given a 2D board containing 'X' and 'O' (the letter O), 
 * capture all regions surrounded by 'X'.

 * A region is captured by flipping all 'O's into 'X's in that surrounded region.

 * For example,
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * After running your function, the board should be:
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <queue>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>> &board) {
		if (board.size() <= 2 || board[0].size() <= 2) {
			return;
		}
		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < col; ++i) {
			if (board[0][i] == 'O')
				process(board, 0, i, row, col);
		}
		for (int i = 0; i < row; ++i) {
			if (board[i][col-1] == 'O')
				process(board, i, col - 1, row, col);
		}
		for (int i = 0; i < col; ++i) {
			if (board[row-1][i] == 'O')
				process(board, row - 1, i, row, col);
		}
		for (int i = 0; i < row; ++i) {
			if (board[i][0] == 'O')
				process(board, i, 0, row, col);
		}

		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (board[i][j] == 'A')
					board[i][j] = 'O';
				else
					board[i][j] = 'X';
			}
		}
	}
	void process(vector<vector<char>> &board, int x, int y, int row, int col) {
		typedef pair<int, int> point;
		int direc[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
		board[x][y] = 'A';
		/*for (int i = 0; i < 4; ++i) {
			int mx = x + direc[i][0];
			int my = y + direc[i][1];
			if (mx >= 0 && mx<row && my >= 0 && my <= col && board[mx][my] == 'O') {
				process(board, mx, my, row, col);
			}
		}*/
		queue<point> os;
		os.push(point(x, y));
		while (!os.empty()) {
			x = os.front().first;
			y = os.front().second;
			os.pop();
			for (int i = 0; i < 4; ++i) {
				int mx = x + direc[i][0];
				int my = y + direc[i][1];
				if (mx>=0 && mx<row && my>=0 && my<=col && board[mx][my] == 'O') {
					board[mx][my] = 'A';
					os.push(point(mx, my));
				}
			}
		}
	}
};
int main()
{
	vector<vector<char>> b(4);
	for (int i = 0; i < 4; ++i) {
		b[i].resize(4);
		for (int j = 0; j < 4; ++j) {
			b[i].push_back('X');
		}
	}
	b[1][1] = 'O';
	b[1][2] = 'O';
	b[2][2] = 'O';
	b[1][3] = 'O';
	Solution s = Solution();
	s.solve(b);
	
	return 0;
}
