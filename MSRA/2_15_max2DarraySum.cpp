/* Title:
 * 二维矩阵中的最小子矩阵和
 * 如果穷举的话时间复杂度是O(N*N*M*M)
 * 另一种方法是穷举一个维度上的所有组合，那么在另一个维度上可以通过O(1)的时间
 * 获得子矩阵和。复杂度降低至O(N*N*M)
 * 这里的进一步优化是在小维度上穷举。复杂度是O(N*M*min(N,M))
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<cassert>

using namespace std;

class Solution {
public:
	//根据输入数组，获得和矩阵，从而可以根据和矩阵快速求出子矩阵和。
	vector<vector<int>> genSumMatrix(vector<vector<int>> nums) {
		int row = nums.size();
		int col = nums[0].size();
		vector<vector<int>> sum(row, vector<int>(col, 0));
		sum[0][0] = nums[0][0];
		for (int i = 1; i < row; ++i)
			sum[i][0] = sum[i-1][0] + nums[i][0];
		for (int i = 1; i < col; ++i)
			sum[0][i] = sum[0][i-1] + nums[0][i];
		for (int i = 1; i < row; ++i) {
			for (int j = 1; j < col; ++j) {
				sum[i][j] = nums[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
			}
		}
		return sum;
	}
};


int main(void)
{
	Solution s;
	vector<vector<int>> init{ { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<vector<int>> sum = s.genSumMatrix(init);
	for (auto vec : sum) {
		for (auto num : vec)
			cout << num << "\t";
		cout << "\n";
	}
	getchar();
	return 0;
}
