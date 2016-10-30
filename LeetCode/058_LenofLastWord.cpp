/* Given a string s consists of upper/lower-case alphabets 
 * and empty space characters ' ', return the length of 
 * last word in the string.

 * If the last word does not exist, return 0.
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
	int lengthOfLastWord(string s) {
		string word("");
		istringstream ss(s);
		while (ss >> word){}
		return word.size();
	}
	//another way is to check from the end;
	int lengthOfLastWord1(string s) {
		int index = s.size() - 1;
		int res = 0; 
		for (int i = index; i >= 0; --i) {
			if (res && s[i] == ' ')
				return res;
			if (s[i] != ' ')
				++res;
		}
	}
};
int main()
{
	Solution s = Solution();

	cout << s.lengthOfLastWord("sdf sdf sdf sdfef sf");
	system("pause");
	return 0;
}