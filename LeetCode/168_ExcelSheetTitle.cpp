/* Given a positive integer, return its corresponding 
 * column title as appear in an Excel sheet.
 * For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
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
	string convertToTitle(int n) {
		string res;
		while (n) {
			res = char(((n % 26) ? (n % 26) : 26) -1 + 'A') + res;
			n = (n % 26) ? n / 26 : n / 26 - 1;
		}
		return res;
	}
	string convertToTitle1(int n) {
		string res;
		while (n) {
			n -= 1;
			res = char(n % 26 + 'A') + res;
			n /= 26;
		}
		return res;
	}
};
int main()
{
	Solution s = Solution();
	
	system("pause");
	return 0;
}