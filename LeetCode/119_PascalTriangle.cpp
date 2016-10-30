/* Given an index k, return the kth row of the Pascal's triangle.
 * For example, given k = 3,
 * Return [1,3,3,1].

 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
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
	//space, O(K^2)0ms
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> res;
		for (int i = 0; i <= rowIndex; ++i) {
			res.push_back(vector<int>(i + 1, 1));
			for (int j = 1; j < res[i].size()-1; ++j) {
				res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
			}
		}
		return res[rowIndex];
	}
	//space,o(k)
	vector<int> getRow1(int rowIndex) {
		vector<int> res(rowIndex+1, 0);
		res[0] = 1;
		for (int i = 0; i < rowIndex+1; ++i) {
			for (int j = i; j>0; --j) {
				res[j] += res[j - 1];
			}
		}
		return res;
	}
};
int main()
{
	Solution s = Solution();
	vector<int> a = s.getRow1(4);
	for (auto i : a)
		cout << i;
	system("pause");
	return 0;
}