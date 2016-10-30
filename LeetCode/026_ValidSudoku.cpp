/* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 * The Sudoku board could be partially filled, where empty cells are 
 * filled with the character '.'.
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. 
 * Only the filled cells need to be validated.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
	//28ms
	bool isValidSudoku(vector<vector<char>>& board) {
		auto rsz = board.size();
		auto csz = board[0].size();
		if (rsz != 9 || csz != 9)
			return false;

		vector<vector<bool>> col(rsz, (vector<bool>(rsz, false)));
		vector<vector<bool>> row(rsz, (vector<bool>(rsz, false)));
		vector<vector<bool>> squ(rsz, (vector<bool>(rsz, false)));

		for (decltype(rsz) i = 0; i < rsz; ++i) {
			for (decltype(rsz) j = 0; j < rsz; ++j) {
				if (board[i][j] == '.')
					continue;
				int val = board[i][j] - '1';
				if (row[i][val] || col[j][val] || squ[(i / 3)*3 + j / 3][val])
					return false;
				row[i][val] = true;
				col[j][val] = true;
				squ[(i/3)*3+j/3][val] = true;
			}
		}
		return true;
	}
	//12ms use array insteadly
	bool isValidSudoku1(vector<vector<char>>& board) {
		int row[9][9] = { 0 };
		int col[9][9] = { 0 };
		int squ[9][9] = { 0 };

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				int val = board[i][j] - '1';
				if (row[i][val] || col[j][val] || squ[(i / 3) * 3 + j / 3][val])
					return false;
				row[i][val] = 1;
				col[j][val] = 1;
				squ[(i / 3) * 3 + j / 3][val] = 1;
			}
		}
		return true;
	}
};

int main()
{
	Solution s = Solution();

	system("pause");
	return 0;
}