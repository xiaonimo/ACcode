/* Title:
 * Given an array of integers A and let n to be its length.
 * Assume Bk to be an array obtained by rotating the array A 
 * k positions clock-wise, we define a "rotation function" F on A as follow:

 * Note:
 * n is guaranteed to be less than 105.

 * Example:
 * A = [4, 3, 2, 6]
 * F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
 * F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
 * F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
 * F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
 * So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>

using namespace std;

class Solution {
public:
	//TLE
	int maxRotateFunction(vector<int>& A) {
		if (A.empty()) return 0;
		int res = INT_MIN;
		int sz = (int)A.size();
		for (int i = 0; i < sz; ++i) {
			int index = i;
			int facotr = 0;
			int sum = 0;
			while (index < i + sz) {
				sum += facotr*A[index%sz];
				++facotr;
				++index;
			}
			if (sum > res) res = sum;
		}
		return res;
	}
	//利用上一次计算的结果。
	int maxRotateFunction1(vector<int>& A) {
		if (A.empty()) return 0;
		int sz = A.size();
		long long res = 0, tmp = 0;
		long long sum = 0;//这里应该避免溢出风险
		for (int i = 0; i < sz; ++i) {
			res += i*A[i];//第一个rotate值
			sum += A[i];//数组的和
		}
		tmp = res;
		for (int i = 1; i < sz; ++i) {
			tmp = tmp - sum + sz * A[i - 1];//根据上一步计算的值，计算下一个rotate值
			res = max(tmp, res);//保存最大值
		}
		return res;
	}
};

int main(){
	Solution s;
	cout << s.maxRotateFunction1(vector<int>{4,3,2,6});
	//cout << (0 + 1 * INT_MIN);
	system("pause");
	return 0;
}
