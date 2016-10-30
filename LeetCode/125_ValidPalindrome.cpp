/* Given a string, determine if it is a palindrome, 
 * considering only alphanumeric characters and ignoring cases.

 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.

 * Note:
 * Have you consider that the string might be empty? 
 * This is a good question to ask during an interview.

 * For the purpose of this problem, we define empty string as valid palindrome.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	bool isPalindrome2(string s) {
		if (s.size() <= 1) {
			return true;
		}
		for (int i = 0, j = s.size() - 1; i < j;) {
			while (!(s[i]>='a' && s[i]<='z'||s[i]>='A'&&s[i]<='Z' || s[i]>='0'&&s[i]<='9'&&i<s.size())) {
				++i;
			}
			if (i >= s.size()) {
				return true;
			}
			while (!(s[j]>='a' && s[j] <= 'z' || s[j] >= 'A'&&s[j] <= 'Z' || s[j] >= '0'&&s[j] <= '9')) {
				--j;
			}
			if (toupper(s[i++]) != toupper(s[j--])){
				return false;
			}
		}
		return true;
	}
};
int main()
{
	Solution s = Solution();
	string str1 = "A man, a plan, a canal: Panama";
	string str2 = ".a.";
	cout << (s.isPalindrome2(str2) ? "true" : "false");
	system("pause");
	return 0;
}