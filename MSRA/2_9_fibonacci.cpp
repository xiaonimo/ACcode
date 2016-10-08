/* 题目：
 * Fibonacci
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	//方法1：最简单的递归方式，但是重复计算部分值。
	int f1(int n);
	int f2(int n);
	//方法2：申请O(n)空间，记录需要多次计算的值。
	int f3(int n);
	//方法3，根据fibonacci的特征方程，求解地推公式
	//特征方程是x^2 = x + 1;
	//但是递归公式中引入了无理数，导致结果不准确。
};
int Solution::f1(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return f1(n - 1) + f1(n - 2);
}
int Solution::f2(int n) {
	int f1 = 0, f2 = 1;
	int res = 0;
	for (int i = 2; i <= n; ++i) {
		res = f1 + f2;
		f1 = f2;
		f2 = res;
	}
	return res;
}
int Solution::f3(int n) {
	int *arr = new int[n+1];
	arr[0] = 0, arr[1] = 1;
	for (int i = 2; i < n + 1; ++i)
		arr[i] = arr[i - 1] + arr[i - 2];
	int res = arr[n];
	delete []arr;
	return res;
}
int main(){
	Solution s = Solution();
	for (int i = 1; i <= 10; ++i)
		cout << s.f2(i) << endl;
	system("pause");
	return 0;
}
