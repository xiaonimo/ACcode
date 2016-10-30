/* Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
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
	//3ms,o(n),but it's not concise
	string addBinary(string a, string b) {
		string &l_str = a.size() > b.size() ? a : b;
		string &s_str = b.size() < a.size() ? b : a;
		string res("");
		int carry = 0;
		for (int i = s_str.size() - 1; i >= 0; --i) {
			//cout << (int)l_str[i + l_str.size() - s_str.size()] << (int)s_str[i];
			int dig = carry + l_str[i + l_str.size() - s_str.size()] + s_str[i] - '0' - '0';
			if (dig == 3) {
				res += "1";
				carry = 1;
			}
			else if (dig == 2) {
				res += "0";
				carry = 1;
			}
			else if (dig == 1) {
				res += "1";
				carry = 0;
			}
			else {
				res += "0";
				carry = 0;
			}
		}
		for (int i = l_str.size() - s_str.size() - 1; i >= 0; --i) {
			int dig = carry + l_str[i] - '0';
			if (dig == 0) {
				res += "0";
				carry = 0;
			}
			else if (dig == 1) {
				res += "1";
				carry = 0;
			}
			else {
				res += "0";
				carry = 1;
			}
		}
		if (carry)
			res += "1";
		reverse(begin(res), end(res));
		return res;
	}

	string addBinary1(string a, string b) {
		string res("");
		int carry = 0;
		int ai = a.size()-1, bi = b.size()-1;

		while (ai - 1 >= 0 || bi - 1 >= 0 || carry == 1) {
			carry += ai >= 0 ? a[ai--] - '0' : 0;
			carry += bi >= 0 ? b[bi--] - '0' : 0;
			res = (char)(carry % 2 + '0') + res;
			carry /= 2;
		}
		return res;
	}
};
int main()
{
	string a("1");
	string b("0");
	Solution s = Solution();
	s.addBinary(a, b);
	
	system("pause");
	return 0;
}