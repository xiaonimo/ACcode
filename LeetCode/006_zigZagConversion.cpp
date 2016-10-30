/* The string "PAYPALISHIRING" is written in a zigzag 
 * pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font 
 * for better legibility)

	P   A   H   N
	A P L S I I G
	Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make 
 * this conversion given a number of rows:

 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
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
	//as string order
	string convert(string s, int numRows) {
		if (1 == numRows)
			return s;
		int step = -1;
		int row = 0;
		string res("");
		vector<string> part(numRows, "");
		for (int i = 0; i < (int)s.size(); ++i) {
			//part[row] += s[i];
			part[row].push_back(s[i]);//it's more fast
			if (0 == i % (numRows - 1))
				step = -step;
			row += step;
		}
		for (auto str : part)
			res += str;
		return res;
	}
	//concise way.
	string convert1(string s, int numRows) {
		if (1 == numRows) return s;
		string res("");
		vector<string> part(numRows);
		int i = 0, j = 0;
		while (i < s.size()) {
			while (j < numRows && i < s.size()) {
				part[j++] += s[i++];
			}
			j -= 2;
			while (j > 0 && i < s.size()) {
				part[j--] += s[i++];
			}
		}
		for (auto str : part)
			res += str;
		return res;
	}
	//as result order
	string convert2(string s, int numRows) {
		numRows = min((int)s.size(), numRows);
		if (1 == numRows)
			return s;
		int step1 = 0, step2 = 0;
		string zigzag("");
		for (int i = 0; i < numRows; ++i) {
			int cur = i;
			step1 = 2 * (numRows - i - 1);
			step2 = 2 * i;
			zigzag.push_back(s[cur]);
			while (cur < s.size()) {
				if (step1) {
					cur += step1;
					if (cur < s.size())
						zigzag.push_back(s[cur]);
				}
				if (step2) {
					cur += step2;
					if (cur < s.size())
						zigzag.push_back(s[cur]);
				}
			}
		}
		return zigzag;
	}
};

int main()
{
	Solution s = Solution();
	cout << s.convert2("a", 2);
	system("pause");
	return 0;
}