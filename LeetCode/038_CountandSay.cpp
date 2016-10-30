/* "Count and Say problem" Write a code to do following:
 * n String to print
 * 0 1
 * 1 1 1
 * 2 2 1
 * 3 1 2 1 1
 * ...
 * Base case: n = 0 print "1"
 * for n = 1, look at previous string and write number of 
 * times a digit is seen and the digit itself. In this case,
 * digit 1 is seen 1 time in a row... so print "1 1"
 * for n = 2, digit 1 is seen two times in a row, so print "2 1"
 * for n = 3, digit 2 is seen 1 time and then digit 1 is seen 1 so print "1 2 1 1"
 * for n = 4 you will print "1 1 1 2 2 1"

 * Consider the numbers as integers for simplicity. e.g. 
 * if previous string is "10 1" then the next will be "1 10 1 1" 
 * and the next one will be "1 1 1 10 2 1"
*/
#include <iostream>
#include <sstream>
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
	//loop
	string countAndSay(int n) {
		string prvStr("1");
		for (int i = 1; i < n; ++i) {
			int j = 1;
			int cnt = 1;
			string curStr;
			while (j < prvStr.size()) {
				if (prvStr[j] == prvStr[j - 1]) {
					++cnt;
				}
				else {
					curStr = curStr + to_string(cnt) + prvStr[j-1];
					cnt = 1;
				}
				++j;
			}
			curStr = curStr + to_string(cnt) + prvStr[j - 1];
			prvStr = curStr;
		}
		return prvStr;
	}
	//revursion
	string countAndSay1(int n) {
		if (n==1) return string("1");
		string resStr;
		int cnt = 1;
		string prvStr = countAndSay1(n - 1);
		for (int i = 1; i < prvStr.size(); ++i) {
			if (prvStr[i] == prvStr[i - 1]) {
				++cnt;
			}
			else {
				resStr = resStr + to_string(cnt) + prvStr[i - 1];
				cnt = 1;
			}
		}
		resStr = resStr + to_string(cnt) + prvStr.back();
		return resStr;
	}
};
int main()
{
	Solution s = Solution();
	cout << s.countAndSay(2);
	system("pause");
	return 0;
}