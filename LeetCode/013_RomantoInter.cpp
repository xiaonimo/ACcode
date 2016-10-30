/* Given a roman numeral, convert it to an integer.

 * Input is guaranteed to be within the range from 1 to 3999.
 */
/*
 * I=1;
 * V=5
 * X=10
 * L=50
 * C=100
 * M=1000
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int res = 0;
		char last = 'I';
		unordered_map<char, int> hmap;
		hmap['I'] = 1;
		hmap['V'] = 5;
		hmap['X'] = 10;
		hmap['L'] = 50;
		hmap['C'] = 100;
		hmap['D'] = 500;
		hmap['M'] = 1000;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (hmap[s[i]] >= hmap[last]) {
				res += hmap[s[i]];
				last = s[i];
			}
			else {
				res -= hmap[s[i]];
			}
		}
		return res;
	}

	int romanToInt1(string s) {
		int res = 0;
		char last = 'I';
		int hmap[256];
		hmap['I'] = 1;
		hmap['V'] = 5;
		hmap['X'] = 10;
		hmap['L'] = 50;
		hmap['C'] = 100;
		hmap['D'] = 500;
		hmap['M'] = 1000;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (hmap[s[i]] >= hmap[last]) {
				res += hmap[s[i]];
				last = s[i];
			}
			else {
				res -= hmap[s[i]];
			}
		}
		return res;
	}
};
int main()
{
	Solution s = Solution();
	string ru("MCMXCVI");
	cout << s.romanToInt(ru) << endl;

	system("pause");
	return 0;
}