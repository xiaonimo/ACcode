/* Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
	[
		 [1],
		[1,1],
	   [1,2,1],
	  [1,3,3,1],
	 [1,4,6,4,1]
	]
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <set>
using namespace std;

class Solution {
public:
	//0ms,easy,by definition
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res;
		if (numRows <= 0)
			return res;
		res.push_back({});
		res[0].push_back(1);
		if (numRows == 1) 
			return res;
		for (int i = 1; i < numRows; ++i) {
			res.push_back({});
			res[i].push_back(1);
			for (unsigned int j = 1; j < res[i - 1].size(); ++j) {
				res[i].push_back(res[i - 1][j] + res[i - 1][j - 1]);
			}
			res[i].push_back(1);
		}
		return res;
	}

	//clean and neat one
	vector<vector<int>> generate1(int numRows) {
		vector<vector<int>> res;
		for (int i = 0; i < numRows; ++i) {
			res.push_back(vector<int>(i + 1, 1));
			for (int j = 1; j < i; ++j) {
				res[i][j] = res[i-1][j] + res[i-1][j-1];
			}
		}
		return res;
	}
};

int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}