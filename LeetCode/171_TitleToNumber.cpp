/* Related to question Excel Sheet Column Title

 * Given a column title as appear in an Excel sheet, 
 * return its corresponding column number.

 * For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int titleToNumber1(string s) {
		int res = 0;
		int k = 1;
		int cnt = s.size();
		for (int i = 0; i < cnt; ++i) {
			//Using pow, takes the same time ,8ms
			//res += (s[cnt - i - 1] - 'A' + 1) * pow(26, i);
			res += (s[cnt - i - 1] - 'A' + 1) * k;
			k *= 26;
		}
		return res;
	}
	//oneline solution,16ms, slow.
	int titleToNumber2(string s) {
		return s != "" ? 26 * titleToNumber2(s.substr(0, s.size() - 1)) + s[s.size() - 1] - 'A' + 1 : 0;
	}
};
int main()
{
	Solution s = Solution();
	string title("ABC");
	cout << s.titleToNumber2(title);
	
	system("pause");
	return 0;
}