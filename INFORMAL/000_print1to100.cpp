/* 题目：
 * 不使用循环或者递归，如何从1打印到100
 */
#include<iostream>  
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
	static int a;
	Solution(){ cout << a++ << endl; }
};
int Solution::a = 1;
int main(){
	Solution s[100];
	system("pause");
	return 0;
}
