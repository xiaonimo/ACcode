/* Implement atoi to convert a string to an integer.
 * Hint: 
 * Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below and 
 * ask yourself what are the possible input cases.
 * Notes: 
 * It is intended for this problem to be specified vaguely 
 * (ie, no given input specs). You are responsible to gather 
 * all the input requirements up front. 
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
#include <sstream>
using namespace std;

class Solution {
public:
	//6ms
	//1.字符串中有'+''-'符号
	//2.存在空字符，空格，字符串的开始末尾，或者数字中间
	//3.越界
	//4.不能使用如下代码来判断是否越界
	/*
		tsum = sum;
		sum = sum*10+(str[i]-'0');
		if ((sum - (str[i]-'0'))/10 != tsum) {
			//overflow
			//eg.INT_MAX+1;
		}
	*/
	int myAtoi(string str) {
		int n = (int)str.size();
		long long sum = 0;
		bool isNum = false;
		bool positive = true;
		for (int i = 0; i < n; ++i) {
			if (!isNum && '-' == str[i]) {
				isNum = true;
				positive = false;
			}
			else if (!isNum && '+' == str[i]) {
				isNum = true;
			}
			else if (!isNum && ' ' == str[i])
				continue;
			else if (str[i] <= '9' && str[i] >= '0') {
				isNum = true;
				sum = sum * 10 + (long long)(str[i] - '0');
				if (positive && sum > INT_MAX)
					return INT_MAX;
				if (!positive && (-sum) < INT_MIN)
					return INT_MIN;
			}
			else {
				break;
			}
		}
		return positive ? sum : -sum;
	}
	//anther good way. 
	int myAtoi1(string str) {
		int sign = 1, base = 0, i = 0;
		while (str[i] == ' ') { i++; }
		if (str[i] == '-' || str[i] == '+') {
			sign = 1 - 2 * (str[i++] == '-');
		}
		while (str[i] >= '0' && str[i] <= '9') {
			//maybe a good way to check overflow.
			if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				return (sign == 1) ? INT_MAX : INT_MIN;
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}
};
int main()
{
	Solution s = Solution();
	//cout << s.myAtoi("2147483648");
	system("pause");
	return 0;
}